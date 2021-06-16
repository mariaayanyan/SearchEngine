#include "WebRepository/WebRepository.h"
#include "LinkRepository/LinkRepository.h"
#include "DocumentRepository/DocumentRepository.h"
#include "PageLoader/PageLoader.h"
#include "HtmlDocument/HtmlDocument.h"
#include "LinkExtractor/LinkExtractor.h"
#include "DocumentExtractor/DocumentExtractor.h"

#include <vector>
#include <string>
#include <algorithm>

int main()
{
    WebRepository webrep;
    LinkRepository linkrep;
    DocumentRepository docrep;
    PageLoader loader;
    LinkExtractor linkExtractor;
    DocumentExtractor documentExtractor;

    std::vector<Website> websites = webrep.getAll();

    for(auto& website : websites)
    {
        linkrep.save(LinkEntry(website.getHomepage(), website.getDomain(), LinkStatus::WAITING));

        while(true)
        {
            std::vector<LinkEntry> entries = linkrep.getByDomain(website.getDomain());

            if(entries.empty())
                break;
            
            for(auto& entry : entries)
            {
                LoadResult result = loader.load(entry.getUrl());
                long status = result.getStatus();

                if(status < 200 || status >= 300)
                {
                    entry.updateTime();
                    entry.setStatus(LinkStatus::ERROR);
                    linkrep.save(entry);
                    continue;
                }

                std::string html = *result.getBody().get();
                HtmlDocument document(html);               

                document.parse();

                std::vector<std::string> links = linkExtractor.extract(document, result.getEffectiveUrl()); 
                
                // remove links with a different domain
                links.erase(std::remove_if(links.begin(), links.end(), [&website](const std::string& link)
                {
                    int pos = link.find("://");
                    pos += 3;
                    int start = pos;
                    pos = link.find("/", start);

                    if(link.find("www.") == start)
                        start += 4;

                    return link.substr(start, pos - start) == website.getDomain();

                }), links.end());
                
                for(auto& link : links)
                {
                    if(linkrep.getByUrl(link).empty())
                        linkrep.save(LinkEntry(link, website.getDomain(), LinkStatus::WAITING));
                }

                DocumentInfo info = documentExtractor.extract(document);
                docrep.save(Document(entry.getUrl(), info.getTitle(), info.getDescription(), info.getText()));

                entry.setStatus(LinkStatus::SUCCESS);
                entry.updateTime();
                linkrep.save(entry);
            }
        }

        website.updateTime();
        webrep.save(website);
    }
}