/**
 * HtmlNode 
 */

#ifndef HTML_NODE
#define HTML_NODE

#include <gumbo.h>
#include <vector>

class HtmlNode
{
    protected:
        GumboNode* node;
        GumboVector* gumboChildren;
    public:
        HtmlNode(GumboNode* node);
        virtual bool isElement() const;
        GumboNode* getNode() const;
        size_t getChildCount() const;
        GumboNode* getChild(size_t i) const;
};

#endif
