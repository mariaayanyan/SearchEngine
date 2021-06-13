#ifndef WEBSITE
#define WEBSITE

#include <string>
#include <vector>
#include <ctime>

class Website
{
private:
    std::string domain;
    std::string homepage;
    time_t updated;

public:
    Website() = default;
    Website(const std::string& domain, const std::string& homepage, time_t time = 0);
    
    std::string getDomain() const;
    std::string getHomepage() const;
    std::time_t getLastCrawlTime() const;
};

#endif
