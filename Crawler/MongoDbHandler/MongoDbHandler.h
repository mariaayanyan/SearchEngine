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

public:
    mongocxx::database db;
    mongocxx::collection collection;
    static mongocxx::instance instance;

    MongoDbHandler(const std::string& db, const std::string& collection, const std::string& uri = "mongodb://0.0.0.0:27017") :
                                uri(mongocxx::uri(uri.c_str())), client(mongocxx::client(this->uri)), 
                                db(this->client[db]), collection(this->db[collection])
    {

    }

    template <typename T>
    bool addItemToDb(const T& item, std::function<bsoncxx::document::value(const T&)> function)
    {
        bsoncxx::document::value docToAdd = function(item);
        bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collection.insert_one(docToAdd.view());

        if(result)
            return true;

        return false;
    }

    
    template <typename T>
    bool updateItem(const T& item, std::function<bsoncxx::document::value(const T&)> query_function, 
                                        std::function<bsoncxx::document::value(const T&)> update_function)
    {
        bsoncxx::document::value queryDoc = query_function(item);
        bsoncxx::document::value updateDoc = update_function(item);
        
        bsoncxx::stdx::optional<mongocxx::result::update> result = collection.update_one(queryDoc.view(), updateDoc.view());

        if(result)
            return result->modified_count() > 0;
        
        return false;
    }

    template <typename T>
    bool removeItemsFromDb(const T& item, std::function<bsoncxx::document::value(const T&)> query_function)    
    {
        bsoncxx::document::value queryDoc = query_function(item);
        bsoncxx::stdx::optional<mongocxx::result::delete_result> result = collection.delete_many(queryDoc.view());

        if(result)
            return result->deleted_count() > 0;
        
        return false;
    }

};  

mongocxx::instance MongoDbHandler::instance{};

#endif
