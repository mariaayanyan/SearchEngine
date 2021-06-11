#ifndef MONGO_DB_HANDLER
#define MONGO_DB_HANDLER

#include <string>   
#include <functional>
#include <bsoncxx/json.hpp>
#include <bsoncxx/types.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/collection.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

class MongoDbHandler
{
private:
    mongocxx::uri uri;
    mongocxx::client client;
    mongocxx::database db;
    mongocxx::collection collection;
    
public:
    static mongocxx::instance instance;

    MongoDbHandler(const std::string& db, const std::string& collection, const std::string& uri = "mongodb://0.0.0.0:27017") :
                                uri(mongocxx::uri(uri.c_str())), client(mongocxx::client(this->uri)), 
                                db(this->client[db]), collection(this->db[collection])
    {

    }

    template <typename T>
    void addItemToDb(const T& item, std::function<bsoncxx::document::value(const T&)> function)
    {
        bsoncxx::document::value docToAdd = function(item);
        collection.insert_one(docToAdd.view());
    }

    
    template <typename T>
    void updateItems(const T& item, std::function<bsoncxx::document::value(const T&)> query_function, 
                                        std::function<bsoncxx::document::value(const T&)> update_function)
    {
        //bsoncxx::document::value queryDoc = builder << "_id" << documentId << bsoncxx::builder::stream::finalize;
        bsoncxx::document::value queryDoc = query_function(item);
        bsoncxx::document::value updateDoc = update_function(item);
        
        collection.update_many(queryDoc.view(), updateDoc.view());
    }

    template <typename T>
    void removeItemsFromDb(const T& item, std::function<bsoncxx::document::value(const T&)> query_function)    
    {
        bsoncxx::document::value queryDoc = query_function(item);
        collection.delete_many(queryDoc.view());
    }

};  

mongocxx::instance MongoDbHandler::instance{};

#endif
