project(LinkRepository)

add_library(
    LinkRepository SHARED

    LinkEntry.h
    LinkEntry.cpp

    LinkRepository.h
    LinkRepository.cpp

    LinkStatus.h
)

target_link_libraries(LinkRepository)