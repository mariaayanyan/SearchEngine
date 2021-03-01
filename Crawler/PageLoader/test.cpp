#include "PageLoader.h"

#include <iostream>

int main()
{
    PageLoader loader;
    LoadResult res = loader.load("https://ru.wikipedia.org/wiki/Modus_ponens");
    std::cout << res.getStatus() << std::endl << std::endl;
    std::cout << res.getBody();
}
