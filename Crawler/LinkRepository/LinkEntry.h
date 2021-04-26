#ifndef LINK_ENTRY
#define LINK_ENTRY

#include <ctime>
#include <string>

class LinkEntry
{
    private:
        time_t creationTime;
        bool isCrawled;
        std::string url;
        int id;
};

#endif
