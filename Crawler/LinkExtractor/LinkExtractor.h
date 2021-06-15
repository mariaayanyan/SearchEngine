#ifndef LINK_EXTRACTOR
#define LINK_EXTRACTOR

#include "../HtmlDocument/HtmlDocument.h"

#include <vector>
#include <string>

class LinkExtractor
{
    public:
        std::vector<std::string> extract(const HtmlDocument& doc, const std::string& effectiveUrl);
};

#endif
