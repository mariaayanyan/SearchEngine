#include "LoadResult.h"

LoadResult::LoadResult(std::shared_ptr<std::string> body, int status) : body(body), status(status)
{

}

std::shared_ptr<std::string> LoadResult::getBody() const
{
    return body;
}

long LoadResult::getStatus() const
{
    return status;  
}
