#include "HtmlElement.h"

HtmlElement::HtmlElement(GumboNode* node) : HtmlNode(node)
{
    
}

bool HtmlElement::isElement() const
{
    return true;
}


bool HtmlElement::isTagA() const
{
    return node->v.element.tag == GUMBO_TAG_A;
}

bool HtmlElement::isTextTag() const
{
    auto tag = node->v.element.tag;
    return tag != GUMBO_TAG_SCRIPT && tag != GUMBO_TAG_STYLE;
}

bool HtmlElement::isTitleTag() const
{
    return node->v.element.tag == GUMBO_TAG_TITLE;
}

bool HtmlElement::isDescriptionTag() const
{
    return node->v.element.tag == GUMBO_TAG_META;
}

std::string HtmlElement::getAttribute(const std::string& name) const
{
    GumboAttribute* attr = gumbo_get_attribute(&node->v.element.attributes, name.c_str());
    
    if(attr)
        return attr->value;
        
    return "";
}

std::string HtmlElement::getInnerText() const
{
   std::string innerText;

    for (size_t i = 0; i < getChildCount(); ++i) 
    {
        if(getChild(i)->type == GUMBO_NODE_TEXT)
            innerText += getChild(i)->v.text.text; 
    }

    return innerText;
}