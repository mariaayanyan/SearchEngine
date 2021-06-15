#ifndef DOCUMENT_REPOSITORY
#define DOCUMENT_REPOSITORY

#include "../MongoDbHandler/MongoDbHandler.h"
#include "Document.h"

#include <vector>

class DocumentRepository
{
private:
    MongoDbHandler handler;
public:
    DocumentRepository();

    std::vector<Document> getAll();

    std::vector<Document> getByUrl(const std::string& url);

    void save(const Document& document);
};

#endif
