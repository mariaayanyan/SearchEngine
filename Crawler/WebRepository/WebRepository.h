#ifndef WEB_REPOSITORY
#define WEB_REPOSITORY

#include "Website.h"
#include "../MongoDbHandler/MongoDbHandler.h"

#include <vector>

class WebRepository
{
private:
    MongoDbHandler handler;
public:
    WebRepository();
    std::vector<Website> getAll();
    void save(const Website& website);
};

#endif
