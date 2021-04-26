#include "HtmlNode.h"

HtmlNode::HtmlNode(GumboNode* node) : node(node)
{
    GumboVector* gumboChildren = &node->v.element.children;

    for(size_t i = 0; i < gumboChildren->length; ++i)
        children.push_back(static_cast<GumboNode*>(gumboChildren->data[i]));
}

bool HtmlNode::isElement() const
{
    return node->type == GUMBO_NODE_ELEMENT; 
}

GumboNode* HtmlNode::getNode() const
{
    return node;
}

size_t HtmlNode::getChildCount() const
{
    return children.size();
}

GumboNode* HtmlNode::getChild(size_t i) const
{
    return children[i];
}
