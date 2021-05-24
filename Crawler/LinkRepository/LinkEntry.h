#ifndef LINK_ENTRY
#define LINK_ENTRY

#include <ctime>
#include <string>
#include "LinkStatus.h"

class LinkEntry
{
    private:
        int id;
        std::string url;
        int websiteId;
        LinkStatus status;
        std::time_t lastUpdate;
    
    public:
        LinkEntry() = default;
        LinkEntry(const std::string& url, LinkStatus status, const std::time_t& lastUpdate, int id = 0, int websiteId = 0);

        int getId() const;
        std::string getUrl() const;
        int getWebsiteId() const;
        LinkStatus getStatus() const;
        std::time_t getLastUpdateTime() const;
};

#endif
