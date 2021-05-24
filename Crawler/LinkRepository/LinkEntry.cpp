#include "LinkEntry.h"

LinkEntry::LinkEntry(const std::string& url, LinkStatus status, const std::time_t& lastUpdate, int id, int websiteId)
                    : url(url), status(status), lastUpdate(lastUpdate), id(id), websiteId(websiteId)

{

}
int LinkEntry::getId() const
{
    return this->id;
}

std::string LinkEntry::getUrl() const
{
    return this->url;
}

int LinkEntry::getWebsiteId() const
{
    return this->websiteId;
}

LinkStatus LinkEntry::getStatus() const
{
    return this->status;
}
std::time_t LinkEntry::getLastUpdateTime() const
{
    return this->lastUpdate;
}
