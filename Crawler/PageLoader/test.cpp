#include "PageLoader.h"

#include <iostream>

int main()
{
    PageLoader loader;
    LoadResult res = loader.load("https://github.com/google/gumbo-parser");
    std::cout << res.getStatus() << std::endl << std::endl;
    std::cout << *res.getBody().get() << std::endl;
}
