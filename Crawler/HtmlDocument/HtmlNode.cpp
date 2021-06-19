#include "HtmlNode.h"

HtmlNode::HtmlNode(GumboNode* node) : node(node)
{
    gumboChildren = &node->v.element.children;
}

bool HtmlNode::isElement() const
{
    return this->node->type == GUMBO_NODE_ELEMENT; 
}

GumboNode* HtmlNode::getNode() const
{
    return this->node;
}

size_t HtmlNode::getChildCount() const
{
    return this->gumboChildren->length;
}

GumboNode* HtmlNode::getChild(size_t i) const
{
    return static_cast<GumboNode*>(this->gumboChildren->data[i]);
}
