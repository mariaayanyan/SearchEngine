#include "HtmlDocument.h"

HtmlDocument::HtmlDocument(const std::string& url) : url(url), output(nullptr)
{

}

HtmlDocument::~HtmlDocument()
{
    if(output)
        gumbo_destroy_output(&kGumboDefaultOptions, output);
}

bool HtmlDocument::parse()
{
    output = gumbo_parse(url.c_str());
}

void HtmlDocument::visitElements(std::function<void(const HtmlElement&)> visitor) const
{
    HtmlNode root(output->root);
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
