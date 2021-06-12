#include "Website.h"

Website::Website(const std::string& domain, const std::string& homepage, std::time_t time) :
                    domain(domain), homepage(homepage), updated(time)
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
    return this->updated;
}
