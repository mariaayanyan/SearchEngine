#ifndef DOCUMENT_INFO
#define DOCUMENT_INFO

#include <string>

class DocumentInfo
{
private:
    std::string text;
    std::string title;
    std::string description;
public:
    DocumentInfo() = default;
    DocumentInfo(const std::string& text, const std::string& title, const std::string& description);

    std::string getText() const;
    std::string getTitle() const;
    std::string getDescription() const;
};

#endif
