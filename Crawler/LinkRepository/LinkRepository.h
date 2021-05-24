/**
 * Stores link entries
 */

#ifndef LINK_REPOSITORY
#define LINK_REPOSITORY

#include "LinkEntry.h"
#include "LinkStatus.h"

#include <vector>

class LinkRepository
{
    private:
        std::vector<LinkEntry> source;
    public:
        std::vector<LinkEntry> getAll() const;
        std::vector<LinkEntry> getById(int id, LinkStatus status, int count) const;
        std::vector<LinkEntry> getByUrl(const std::string& url) const;

        /**
         * Updates source with a new entry
         */
        void save(const LinkEntry& entry);
};

#endif
