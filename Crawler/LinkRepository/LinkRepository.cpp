#include "LinkRepository.h"

std::vector<LinkEntry> LinkRepository::getAll() const
{
    return this->source;
}

std::vector<LinkEntry> LinkRepository::getById(int id, LinkStatus status, int count) const
{
    std::vector<LinkEntry> entries;
    int cur = 0;

    for(const LinkEntry& entry : source)
    {
        if(entry.getId() == id && entry.getStatus() == status)
        {
            entries.push_back(entry);
            ++cur;
        }

        if(cur == count)
            break;
    }

    return entries;
}

std::vector<LinkEntry> LinkRepository::getByUrl(const std::string& url) const
{
    std::vector<LinkEntry> entries;

    for(const LinkEntry& entry : source)
        if(entry.getUrl() == url)
            entries.push_back(entry);

    return entries;
}

void LinkRepository::save(const LinkEntry& entry)
{
    source.push_back(entry);
}
