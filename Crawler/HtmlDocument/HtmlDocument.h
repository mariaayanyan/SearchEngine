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
        std::string html;

        void visitElement(const HtmlNode& node, std::function<void(const HtmlElement&)> visitor) const; 
    public:
        HtmlDocument(const std::string& html);
        
        bool parse();
        void visitElements(std::function<void(const HtmlElement&)> visitor) const; 
        
        std::string getHtml() const;
        
        ~HtmlDocument();
};

#endif
