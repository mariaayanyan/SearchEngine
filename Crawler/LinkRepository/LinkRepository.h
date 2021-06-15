/**
 * Stores link entries
 */

#ifndef LINK_REPOSITORY
#define LINK_REPOSITORY

#include "LinkEntry.h"
#include "LinkStatus.h"
#include "../MongoDbHandler/MongoDbHandler.h"

#include <vector>

class LinkRepository
{
    private:
        MongoDbHandler handler;
    public:
        LinkRepository();
        std::vector<LinkEntry> getAll();
        std::vector<LinkEntry> getByDomain(const std::string& domain);
        std::vector<LinkEntry> getByUrl(const std::string& url);
        void save(const LinkEntry& entry);
};

#endif
