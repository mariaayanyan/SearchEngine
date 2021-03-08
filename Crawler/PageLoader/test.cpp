#include "PageLoader.h"

#include <iostream>

int main()
{
    PageLoader loader;
    LoadResult res = loader.load("https://github.com/mariaayanyan/SearchEngine/commit/a0148d41ae9d117c1cf3079bd3f175e4ed1bf300");
    std::cout << res.getStatus() << std::endl << std::endl;
    std::cout << *res.getBody().get() << std::endl;
}
