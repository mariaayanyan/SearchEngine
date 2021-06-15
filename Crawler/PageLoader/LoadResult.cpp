#include "LoadResult.h"

LoadResult::LoadResult(std::shared_ptr<std::string> body, int status, const std::string& effectiveUrl) : body(body), status(status), effectiveUrl(effectiveUrl)
{

}

std::shared_ptr<std::string> LoadResult::getBody() const
{
    return this->body;
}

long LoadResult::getStatus() const
{
    return this->status;  
}

std::string LoadResult::getEffectiveUrl() const
{
    return this->effectiveUrl;
}