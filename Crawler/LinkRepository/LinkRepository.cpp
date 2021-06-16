#include "LinkRepository.h"

LinkRepository::LinkRepository() : handler("SearchEngine", "Links")
{

}

std::vector<LinkEntry> LinkRepository::getAll() 
{
    std::vector<LinkEntry> entries;    
    mongocxx::cursor cursor = handler.collection.find({});

    for(auto doc : cursor)
    {
        std::string url = doc["url"].get_utf8().value.to_string();
        std::string domain = doc["domain"].get_utf8().value.to_string();
        int status = doc["status"].get_int32().value;
        time_t lastUpdate = doc["lastUpdate"].get_int64().value;

        entries.emplace_back(url, domain, LinkStatus(status), lastUpdate);
    }

    return entries;
}

std::vector<LinkEntry> LinkRepository::getByDomain(const std::string& neededDomain) 
{
    std::vector<LinkEntry> entries;    
    
    bsoncxx::document::value queryDoc = bsoncxx::builder::stream::document{} << "domain" << neededDomain << bsoncxx::builder::stream::finalize;
    mongocxx::cursor cursor = handler.collection.find(queryDoc.view());
 
    for(auto doc : cursor)
    {
        std::string url = doc["url"].get_utf8().value.to_string();
        std::string domain = doc["domain"].get_utf8().value.to_string();
        int status = doc["status"].get_int32().value;
        time_t lastUpdate = doc["lastUpdate"].get_int64().value;

        entries.emplace_back(url, domain, LinkStatus(status), lastUpdate);
    }

    return entries;
}


std::vector<LinkEntry> LinkRepository::getByUrl(const std::string& neededUrl) 
{
    std::vector<LinkEntry> entries;    
    
    bsoncxx::document::value queryDoc = bsoncxx::builder::stream::document{} << "url" << neededUrl << bsoncxx::builder::stream::finalize;
    mongocxx::cursor cursor = handler.collection.find(queryDoc.view());
 
    for(auto doc : cursor)
    {
        std::string url = doc["url"].get_utf8().value.to_string();
        std::string domain = doc["domain"].get_utf8().value.to_string();
        int status = doc["status"].get_int32().value;
        time_t lastUpdate = doc["lastUpdate"].get_int64().value;

        entries.emplace_back(url, domain, LinkStatus(status), lastUpdate);
    }

    return entries;
}

void LinkRepository::save(const LinkEntry& entry)
{
    auto queryFunction = [](const LinkEntry& entry)
    {
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value queryDoc = builder << "url" << entry.getUrl() << bsoncxx::builder::stream::finalize;

        return queryDoc;
    };

    auto updateFunction = [](const LinkEntry& entry)
    {
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value updateDoc = builder << 
        "$set" << bsoncxx::builder::stream::open_document << "url" << entry.getUrl() << bsoncxx::builder::stream::close_document << 
        "$set" << bsoncxx::builder::stream::open_document << "domain" << entry.getDomain() << bsoncxx::builder::stream::close_document << 
        "$set" << bsoncxx::builder::stream::open_document << "status" << (int)entry.getStatus() << bsoncxx::builder::stream::close_document << 
        "$set" << bsoncxx::builder::stream::open_document << "lastUpdate" << entry.getLastUpdateTime() << bsoncxx::builder::stream::close_document <<         
        bsoncxx::builder::stream::finalize;

        return updateDoc;
    };


    auto insertFunction = [](const LinkEntry& entry)
    {
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value insertDoc = builder <<
        "url" << entry.getUrl() << 
        "domain" << entry.getDomain() <<
        "status" << (int)entry.getStatus() << 
        "lastUpdate" << entry.getLastUpdateTime() <<
        bsoncxx::builder::stream::finalize;

        return insertDoc;
    };

    if(!handler.updateItem<LinkEntry>(entry, queryFunction, updateFunction))
        handler.addItemToDb<LinkEntry>(entry, insertFunction);
}
