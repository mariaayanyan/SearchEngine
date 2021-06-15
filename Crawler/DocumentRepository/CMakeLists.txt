project(DocumentRepository)

add_library(
    DocumentRepository SHARED

    DocumentRepository.h
    DocumentRepository.cpp

    Document.h
    Document.cpp
)

target_link_libraries(DocumentRepository)
