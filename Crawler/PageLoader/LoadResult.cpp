#include "LoadResult.h"

LoadResult::LoadResult(std::shared_ptr<std::string> body, int status) : body(body), status(status)
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
