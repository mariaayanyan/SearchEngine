#ifndef WEB_REPOSITORY
#define WEB_REPOSITORY

#include "Website.h"

#include <vector>

class WebRepository
{
private:
    std::vector<Website> source;

public:

    std::vector<Website> getAll() const;
    void save(const Website& website);
};

#endif