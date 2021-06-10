#include "MongoDbHandler.h"

MongoDbHandler::MongoDbHandler(const std::string& db, const std::string& collection, const std::string& uri) :
                                uri(mongocxx::uri(uri.c_str())), client(mongocxx::client(this->uri)), 
                                db(this->client[db]), collection(this->db[collection])
{

}

template <typename T>
std::string MongoDbHandler::addItemToDb(const T& item, std::function<bsoncxx::document::value(const bsoncxx::builder::stream::document&, const T&)> function)
{
    auto builder = bsoncxx::builder::stream::document{};
    auto docToAdd = function(builder, item);
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collection.insert_one(docToAdd.view());

    if(result)
    {
        return result->inserted_id;
    }

    return "";
}

template <typename T>
std::string MongoDbHandler::updateItem(const T& item, std::function<bsoncxx::document::value(const bsoncxx::builder::stream::document&, const T&)> function)
{
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::oid documentId(item.getId());

    bsoncxx::document::value queryDoc = builder << "_id" < documentId << bsoncxx::builder::stream::finalize;
    bsoncxx::document::value updateDoc = function(builder, item);
    
    bsoncxx::stdx::optional<mongocxx::result::update> result = collection.update_one(docToAdd.view());

    if(result)
    {
        return result->upserted_id;
    }

    return "";
}

template <typename T>
int MongoDbHandler::removeItemFromDb(const T& item)
{
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::oid documentId(item.getId());

    bsoncxx::document::value queryDoc = builder << "_id" < documentId << bsoncxx::builder::stream::finalize;
    
    bsoncxx::stdx::optional<mongocxx::result::delete_result> result = collection.delete_one(queryDoc.view());

    if(result)
    {
        return result->deleted_count;
    }

    return 0;
}