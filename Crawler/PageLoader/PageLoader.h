#ifndef PAGE_LOADER_H
#define PAGE_LOADER_H

#include "LoadResult.h"

class PageLoader
{
public:
    LoadResult load(const std::string& url);
};

#endif 
