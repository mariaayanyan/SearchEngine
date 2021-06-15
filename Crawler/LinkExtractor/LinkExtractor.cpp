#include "LinkExtractor.h"

std::vector<std::string> LinkExtractor::extract(const HtmlDocument& doc, const std::string& effectiveUrl)
{
    std::vector<std::string> links;
    doc.visitElements([&links, &effectiveUrl](const HtmlElement& elem)
    {
        if(!elem.isTagA())
            return;
        
        std::string href = elem.getAttribute("href");
        if(!href.empty())
        {
            if(href.find("://") == std::string::npos)
            {
                if(href.front() != '/')
                {
                    if(effectiveUrl.back() != '/')
                        href = effectiveUrl + '/' + href;
                    else
                        href = effectiveUrl + href; 
                }
                else
                {
                    int pos = effectiveUrl.find("://");
                    pos += 3;
                    pos = effectiveUrl.find("/", pos);

                    href = effectiveUrl.substr(0, pos) + href; 
                } 
            }    
            links.push_back(href);
        }
            
    });

    return links;
}
