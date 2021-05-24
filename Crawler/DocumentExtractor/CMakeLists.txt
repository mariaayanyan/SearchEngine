project(DocumentExtractor)

add_library(
    DocumentExtractor SHARED

    DocumentExtractor.h
    DocumentExtractor.cpp

    DocumentInfo.h
    DocumentInfo.cpp
)

target_link_libraries(DocumentExtractor)