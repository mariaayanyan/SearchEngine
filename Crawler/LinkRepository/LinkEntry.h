#ifndef LINK_ENTRY
#define LINK_ENTRY

#include <ctime>
#include <string>
#include "LinkStatus.h"

class LinkEntry
{
    private:
        std::string url;
        std::string domain;
        LinkStatus status;
        time_t lastUpdate;
    
    public:
        LinkEntry() = default;
        LinkEntry(const std::string& url, const std::string& domain, LinkStatus status, time_t lastUpdate = 0);

        std::string getUrl() const;
        std::string getDomain() const;
        LinkStatus getStatus() const;
        time_t getLastUpdateTime() const; 

        void setStatus(LinkStatus status);
        void updateTime();
};

#endif
