#include "LinkExtractor.h"

std::set<std::string> LinkExtractor::extract(const HtmlDocument& doc)
{
    std::set<std::string> links;
    doc.visitElements([&links](const HtmlElement& elem)
    {
        if(!elem.isTagA())
            return;
        
        std::string href = elem.getAttribute("href");
        if(!href.empty())
            links.insert(href);
    });

    return links;
}
