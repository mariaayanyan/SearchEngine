project(HtmlDocument)

add_library(
    HtmlDocument SHARED

    HtmlDocument.h
    HtmlDocument.cpp

    HtmlElement.h
    HtmlElement.cpp

    HtmlNode.h
    HtmlNode.cpp
)

target_link_libraries(HtmlDocument -lgumbo)