#include "PageLoader.h"

#include <iostream>

int main()
{
    PageLoader loader;
    LoadResult res = loader.load("https://fuck_you");
    std::cout << res.getStatus() << std::endl << std::endl;
    std::cout << *res.getBody().get() << std::endl;
}
