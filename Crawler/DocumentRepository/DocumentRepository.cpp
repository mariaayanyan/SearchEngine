#include "DocumentRepository.h"

DocumentRepository::DocumentRepository() : handler("SearchEngine", "Documents")
{

}

std::vector<Document> DocumentRepository::getByUrl(const std::string& url)
{
    std::vector<Document> documents;
    bsoncxx::document::value queryDoc = bsoncxx::builder::stream::document{} << "url" << url << bsoncxx::builder::stream::finalize;
    mongocxx::cursor cursor = handler.collection.find(queryDoc.view());

    for(auto doc : cursor)
    {
        std::string url = doc["url"].get_utf8().value.to_string();
        std::string title = doc["title"].get_utf8().value.to_string();
        std::string description = doc["descriprion"].get_utf8().value.to_string();
        std::string text = doc["text"].get_utf8().value.to_string();
        time_t lastUpdated = doc["lastUpdate"].get_int64().value;

        documents.emplace_back(url, title, description, text, lastUpdated);
    }

    return documents;
}

std::vector<Document> DocumentRepository::getAll()
{
    std::vector<Document> documents;
    mongocxx::cursor cursor = handler.collection.find({});

    for(auto doc : cursor)
    {
        std::string url = doc["url"].get_utf8().value.to_string();
        std::string title = doc["title"].get_utf8().value.to_string();
        std::string description = doc["descriprion"].get_utf8().value.to_string();
        std::string text = doc["text"].get_utf8().value.to_string();
        time_t lastUpdated = doc["lastUpdate"].get_int64().value;

        documents.emplace_back(url, title, description, text, lastUpdated);
    }

    return documents;
}

void DocumentRepository::save(const Document& document)
{

    auto queryFunction = [](const Document& document)
    {
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value queryDoc = builder << "url" << document.getUrl() << bsoncxx::builder::stream::finalize;

        return queryDoc;
    };

    auto updateFunction = [](const Document& document)
    {
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value updateDoc = builder << 
        "$set" << bsoncxx::builder::stream::open_document << "url" << document.getUrl() << bsoncxx::builder::stream::close_document << 
        "$set" << bsoncxx::builder::stream::open_document << "title" << document.getTitle() << bsoncxx::builder::stream::close_document << 
        "$set" << bsoncxx::builder::stream::open_document << "description" << document.getDescription() << bsoncxx::builder::stream::close_document << 
        "$set" << bsoncxx::builder::stream::open_document << "text" << document.getText() << bsoncxx::builder::stream::close_document << 
        "$set" << bsoncxx::builder::stream::open_document << "lastUpdate" << document.getLastUpdateTime() << bsoncxx::builder::stream::close_document <<         
        bsoncxx::builder::stream::finalize;

        return updateDoc;
    };


    auto insertFunction = [](const Document& document)
    {
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value insertDoc = builder << 
        "url" << document.getUrl() << 
        "title" << document.getTitle() << 
        "description" << document.getDescription() << 
        "text" << document.getText() << 
        "lastUpdate" << document.getLastUpdateTime() <<         
        bsoncxx::builder::stream::finalize;

        return insertDoc;
    };

    if(!handler.updateItem<Document>(document, queryFunction, updateFunction))
        handler.addItemToDb<Document>(document, insertFunction);
}