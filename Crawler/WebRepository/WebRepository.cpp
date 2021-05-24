#include "WebRepository.h"


void WebRepository::save(const Website& website)
{
    for(int i = 0; i < source.size(); ++i)
    {
        if(source[i].getDomain() == website.getDomain())
            source[i] = website;
    }

    source.push_back(website);
} 

std::vector<Website> WebRepository::getAll() const
{
    return this->source;
}