project(MongoDbHandler)

set(CMAKE_CXX_STANDARD 17)

include("mongo.config")

add_library(
    MongoDbHandler SHARED

    MongoDbHandler.h
    MongoDbHandler.cpp
)

target_link_libraries(MongoDbHandler ${MONGO_FLAGS})
