/**
 * A wrapper class for parsing HTML code.
 */

#ifndef HTML_DOCUMENT
#define HTML_DOCUMENT

#include "HtmlElement.h"
#include <gumbo.h>

#include <string>
#include <functional>

class HtmlDocument
{
    private:
        GumboOutput* output;
        std::string url;
        void visitElement(const HtmlNode& node, std::function<void(const HtmlElement&)> visitor) const; 
    public:
        HtmlDocument(const std::string& url);
        bool parse();
        void visitElements(std::function<void(const HtmlElement&)> visitor) const; 
        ~HtmlDocument();
};

#endif
