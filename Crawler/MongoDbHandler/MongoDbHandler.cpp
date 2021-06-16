#include "MongoDbHandler.h"

MongoDbHandler::MongoDbHandler(const std::string& db, const std::string& collection, const std::string& uri) :
                                uri(mongocxx::uri(uri.c_str())), client(mongocxx::client(this->uri)), 
                                db(this->client[db]), collection(this->db[collection])
{

}
