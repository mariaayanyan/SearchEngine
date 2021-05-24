project(LinkExtractor)

add_library(
    LinkExtractor SHARED

    LinkExtractor.h
    LinkExtractor.cpp
)

target_link_libraries(LinkExtractor)