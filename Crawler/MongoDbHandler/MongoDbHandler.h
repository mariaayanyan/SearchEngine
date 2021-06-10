#ifndef MONGO_DB_HANDLER
#define MONGO_DB_HANDLER

#include <string>   
#include <functional>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
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
    mongocxx::instance instance;
public:
    MongoDbHandler(const std::string& db, const std::string& collection, const std::string& uri = "mongodb://0.0.0.0.27017");

    /**
     * attempts to insert a new item into the database,
     * returns the inserted id on success, an empty string otherwise
     */
    template <typename T>
    std::string addItemToDb(const T& item, std::function<bsoncxx::document::value(const bsoncxx::builder::stream::document&, const T&)> function);
    
    /**
     * attempts to update an item from the database,
     * returns the upserted id on success, an empty string otherwise
     */
    template <typename T>
    std::string updateItem(const T& item, std::function<bsoncxx::document::value(const bsoncxx::builder::stream::document&, const T&)> function);
    
    /**
     * attempts to remoeve an item from the database,
     * returns deleted count
     */
    template <typename T>
    int removeItemFromDb(const T& item);

};

#endif
