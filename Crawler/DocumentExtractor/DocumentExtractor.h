#ifndef DOCUMENT_EXTRACTOR
#define DOCUMENT_EXTRACTOR

#include "../HtmlDocument/HtmlDocument.h"
#include "DocumentInfo.h"

#include <set>
#include <string>

class DocumentExtractor
{
    public:
        DocumentInfo extract(const HtmlDocument& doc) const;
};

#endif
