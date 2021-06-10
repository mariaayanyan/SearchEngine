project(MongoDbHandler)

add_library(
    MongoDbHandler SHARED

    MongoDbHandler.h
    MongoDbHandler.cpp
)

target_link_libraries(MongoDbHandler -lmongocxx -lbsoncxx)