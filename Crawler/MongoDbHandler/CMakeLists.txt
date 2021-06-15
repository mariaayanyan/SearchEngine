cmake_minimum_required(VERSION 3.15)
project(MongoDbHandler)

set(CMAKE_CXX_STANDARD 17)

add_executable(MongoDbHandler test.cpp)

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")


target_link_libraries(MongoDbHandler ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(MongoDbHandler ${LIBBSONCXX_LIBRARIES})
