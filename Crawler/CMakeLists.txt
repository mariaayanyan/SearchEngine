cmake_minimum_required(VERSION 3.0)

project("Crawler")

set(CMAKE_CXX_STANDARD 17)

include("MongoDbHandler/mongo.config")

add_executable(${PROJECT_NAME} Crawler.cpp)

add_subdirectory(PageLoader)
add_subdirectory(HtmlDocument)
add_subdirectory(LinkExtractor)
add_subdirectory(LinkRepository)
add_subdirectory(WebRepository)
add_subdirectory(DocumentRepository)
add_subdirectory(DocumentExtractor)
add_subdirectory(MongoDbHandler)

set_target_properties(PageLoader PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/PageLoader/libPageLoader.so"
)

set_target_properties(HtmlDocument PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/HtmlDocument/libHtmlDocument.so"
)

set_target_properties(LinkExtractor PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/LinkExtractor/libLinkExtractor.so"
)

set_target_properties(MongoDbHandler PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/MongoDbHandler/libMongoDbHandler.so"
)

set_target_properties(LinkRepository PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/LinkRepository/libLinkRepository.so"
)

set_target_properties(WebRepository PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/WebRepository/libWebRepository.so"
)

set_target_properties(DocumentRepository PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/DocumentRepository/libDocumentRepository.so"
)

set_target_properties(DocumentExtractor PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/DocumentExtractor/libDocumentExtractor.so"
)

target_link_libraries(${PROJECT_NAME} PageLoader HtmlDocument LinkExtractor MongoDbHandler LinkRepository WebRepository DocumentExtractor DocumentRepository)
