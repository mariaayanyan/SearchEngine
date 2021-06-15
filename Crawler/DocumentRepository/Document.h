#ifndef DOCUMENT
#define DOCUMENT

#include <string>
#include <ctime>

class Document
{
private:
    std::string url;
    std::string title;
    std::string description;
    std::string text;
    time_t lastUpdate;

public:
    Document(const std::string& url, const std::string& title, const std::string& description, const std::string& text, time_t lastUpdate = 0);

    std::string getUrl() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getText() const;
    time_t getLastUpdateTime() const;

    void updateTime();
};

#endif
