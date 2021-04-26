/**
 * Stores link entries
 */

#ifndef LINK_REPOSITORY
#define LINK_REPOSITORY

#include "LinkEntry.h"

#include <vector>
#include <map>

class LinkRepository
{
    private:
        /**
         * Maps id to link entry
         */
        std::map<int, LinkEntry> source;
    public:
        std::vector<LinkEntry> getAll();
        LinkEntry getById(int id);

        /**
         * Updates source with a new entry
         */
        void save(const LinkEntry& entry);
};

#endif
