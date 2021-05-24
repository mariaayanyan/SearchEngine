#include "Website.h"

Website::Website(const std::string& domain, const std::string& homepage, std::time_t time, int id = 0) :
                    domain(domain), homepage(homepage), updated(time), id(id)
{
    
}   
int Website::getId() const
{
    return this->id;
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
