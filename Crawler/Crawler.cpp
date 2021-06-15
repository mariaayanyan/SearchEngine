#include <WebRepository/WebRepository.h>
#include <LinkRepository/LinkRepository.h>
#include <PageLoader/PageLoader.h>
#include <HtmlDocument/HtmlDocument.h>
#include <LinkExtractor/LinkExtractor.h>

#include <vector>
#include <string>

int main()
{
    WebRepository webrep;
    LinkRepository linkrep;
    PageLoader loader;
    LinkExtractor linkExtractor;

    std::vector<Website> websites = webrep.getAll();

    for(auto& website : websites)
    {
        linkrep.save(LinkEntry(website.getHomepage(), website.getDomain(), LinkStatus::WAITING, 0));

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
                    entry.setStatus(LinkStatus::ERROR);
                    linkrep.save(entry);
                    continue;
                }

                std::string html = *result.getBody().get();
                HtmlDocument document(html);               

                document.parse();

                std::vector<std::string> links = linkExtractor.extract(document, result.getEffectiveUrl()); 

                
            }
        }
    }
}