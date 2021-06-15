#include "LinkEntry.h"

LinkEntry::LinkEntry(const std::string& url, const std::string& domain, LinkStatus status, time_t lastUpdate) : url(url), domain(domain), status(status), lastUpdate(lastUpdate)
{

}

std::string LinkEntry::getUrl() const
{
    return this->url;
}

std::string LinkEntry::getDomain() const
{
    return this->domain;
}

LinkStatus LinkEntry::getStatus() const
{
    return this->status;
}

time_t LinkEntry::getLastUpdateTime() const
{
    return this->lastUpdate;
}

void LinkEntry::setStatus(LinkStatus status)
{
    this->status = status;
}

void LinkEntry::updateTime()
{
    this->lastUpdate = time(nullptr);
}