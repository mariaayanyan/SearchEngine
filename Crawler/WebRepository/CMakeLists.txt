
project(WebRepository)

include("../MongoDbHandler/mongo.config")

add_library(
    WebRepository SHARED

    WebRepository.h
    WebRepository.cpp
    
    Website.h
    Website.cpp
)

target_link_libraries(WebRepository ${MONGO_FLAGS})