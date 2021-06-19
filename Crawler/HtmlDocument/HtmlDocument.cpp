#include "HtmlDocument.h"

HtmlDocument::HtmlDocument(const std::string& html) : html(html), output(nullptr)
{

}

HtmlDocument::~HtmlDocument()
{
    if(this->output)
        gumbo_destroy_output(&kGumboDefaultOptions, this->output);
}

std::string HtmlDocument::getHtml() const 
{
    return this->html;
}

void HtmlDocument::parse()
{
    this->output = gumbo_parse(this->html.c_str());
}

void HtmlDocument::visitElements(std::function<void(const HtmlElement&)> visitor) const
{
    HtmlNode root(this->output->root);
    visitElement(HtmlElement(root.getNode()), visitor);
}

void HtmlDocument::visitElement(const HtmlNode& node, std::function<void(const HtmlElement&)> visitor) const
{
    if(!node.isElement())
        return;

    visitor(node.getNode());

    for(size_t i = 0; i < node.getChildCount(); ++i)
    {
        visitElement(HtmlNode(node.getChild(i)), visitor);
    }
}
