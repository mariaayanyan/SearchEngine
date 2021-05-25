#include "HtmlDocument.h"

HtmlDocument::HtmlDocument(const std::string& url) : url(url), output(nullptr)
{

}

HtmlDocument::~HtmlDocument()
{
    if(this->output)
        gumbo_destroy_output(&kGumboDefaultOptions, this->output);
}

bool HtmlDocument::parse()
{
    this->output = gumbo_parse(this->url.c_str());
}

void HtmlDocument::visitElements(std::function<void(const HtmlElement&)> visitor) const
{
    HtmlNode root(this->output->root);
    visitElement(root, visitor);
}

void HtmlDocument::visitElement(const HtmlNode& node, std::function<void(const HtmlElement&)> visitor) const
{
    if(!node.isElement())
        return;

    visitor(node.getNode());

    for(size_t i = 0; i < node.getChildCount(); ++i)
    {
        visitElement(node.getChild(i), visitor);
    }

}
