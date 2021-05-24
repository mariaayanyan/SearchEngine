project(PageLoader)

add_library(
    PageLoader SHARED

    LoadResult.h
    LoadResult.cpp

    PageLoader.h
    PageLoader.cpp

    CurlException.h
    CurlException.cpp
)

target_link_libraries(PageLoader -lcurl)