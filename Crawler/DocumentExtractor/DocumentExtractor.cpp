#include "DocumentExtractor.h"

DocumentInfo DocumentExtractor::extract(const HtmlDocument& doc) const
{
    std::string text, title, description;
    doc.visitElements([&text, &title, &description](HtmlElement elem)
    {
        if(!elem.isTextTag())
            return;
        
        std::string innerText = elem.getInnerText();

        if(elem.isTitleTag())
            title += innerText;

        if(elem.isDescriptionTag())
            description += innerText;
        
        text += innerText;
    });

    return DocumentInfo(text, title, description);
}
