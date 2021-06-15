#include "Document.h"

Document::Document(const std::string& url, const std::string& title, const std::string& description, const std::string& text, time_t lastUpdate) 
                                                                : url(url), title(title), description(description), text(text), lastUpdate(lastUpdate)
{

}

std::string Document::getUrl() const
{
    return this->url;
}

std::string Document::getTitle() const
{
    return this->title;
}

std::string Document::getDescription() const
{
    return this->description;
}

std::string Document::getText() const
{
    return this->text;
}

time_t Document::getLastUpdateTime() const
{
    return this->lastUpdate;
}

void Document::updateTime()
{
    lastUpdate = time(nullptr);
}
