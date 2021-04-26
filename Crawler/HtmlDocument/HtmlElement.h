#ifndef HTML_ELEMENT
#define HTML_ELEMENT

#include "HtmlNode.h"

#include <string>

class HtmlElement : public HtmlNode
{
    public:
        HtmlElement(GumboNode* node);

        virtual bool isElement() const override;
        bool isTagA() const;
        bool isTextTag() const;
        bool isTitleTag() const;
        bool isDescriptionTag() const;  

        std::string getAttribute(const std::string& name) const;
        std::string getInnerText() const;
};

#endif
