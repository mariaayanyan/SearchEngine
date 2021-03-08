#ifndef PAGE_LOADER_H
#define PAGE_LOADER_H

#include "LoadResult.h"

class PageLoader
{
private:
    static size_t getData(char* buffer, size_t itemSize, size_t itemCount, void* dest);
public:
    LoadResult load(const std::string& url);
};

#endif 
