#include "Website.h"

Website::Website(const std::string& domain, const std::string& homepage, time_t lastUpdate) :
                    domain(domain), homepage(homepage), lastUpdate(lastUpdate)
{
    
}   

std::string Website::getDomain() const
{
    return this->domain;    
}

std::string Website::getHomepage() const
{
    return this->homepage;
}
std::time_t Website::getLastCrawlTime() const
{
    return this->lastUpdate;
}

void Website::updateTime()
{
    this->lastUpdate = time(nullptr);
}