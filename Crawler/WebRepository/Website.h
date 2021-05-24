#ifndef WEBSITE
#define WEBSITE

#include <string>
#include <vector>
#include <ctime>

class Website
{
private:
    int id;
    std::string domain;
    std::string homepage;
    std::time_t updated;

public:
    Website() = default;
    Website(const std::string& domain, const std::string& homePage, std::time_t time, int id = 0);
    
    int getId() const;
    std::string getDomain() const;
    std::string getHomepage() const;
    std::time_t getLastCrawlTime() const;
};

#endif
