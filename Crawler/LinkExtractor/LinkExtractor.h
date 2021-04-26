#ifndef LINK_EXTRACTOR
#define LINK_EXTRACTOR

#include "../HtmlDocument/HtmlDocument.h"

#include <set>
#include <string>

class LinkExtractor
{
    public:
        std::set<std::string> extract(const HtmlDocument& doc);
};

#endif
