#include "WebRepository.h"

WebRepository::WebRepository() : handler("SearchEngine", "Websites")
{

}

void WebRepository::save(const Website& website)
{
    auto queryFunction = [](const Website& website)
    {
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value queryDoc = builder << "domain" << website.getDomain() << bsoncxx::builder::stream::finalize;

        return queryDoc;
    };

    auto updateFunction = [](const Website& website)
    {
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value updateDoc = builder << 
        "$set" << bsoncxx::builder::stream::open_document << "domain" << website.getDomain() << bsoncxx::builder::stream::close_document << 
        "$set" << bsoncxx::builder::stream::open_document << "homepage" << website.getHomepage() << bsoncxx::builder::stream::close_document << 
        "$set" << bsoncxx::builder::stream::open_document << "lastUpdated" << website.getLastCrawlTime() << bsoncxx::builder::stream::close_document <<         
        bsoncxx::builder::stream::finalize;

        return updateDoc;
    };

    auto insertFunction = [](const Website& website)
    {
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value insertDoc = builder << 
        "domain" << website.getDomain() << 
        "homepage" << website.getHomepage() << 
        "lastUpdated" << website.getLastCrawlTime() << 
        bsoncxx::builder::stream::finalize;

        return insertDoc;
    };

    if(!handler.updateItem<Website>(website, queryFunction, updateFunction))
        handler.addItemToDb<Website>(website, insertFunction);

} 

std::vector<Website> WebRepository::getAll()
{
    std::vector<Website> websites;
    mongocxx::cursor cursor = handler.collection.find({});

    for(auto doc : cursor)
    {
        std::string domain = doc["domain"].get_utf8().value.to_string();
        std::string homepage = doc["homepage"].get_utf8().value.to_string();
        time_t updated = doc["lastUpdated"].get_int64().value;

        websites.emplace_back(domain, homepage, updated);
    }

    return websites;    
}