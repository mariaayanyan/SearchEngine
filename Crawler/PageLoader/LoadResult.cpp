#include "LoadResult.h"

LoadResult::LoadResult(const std::string& body, int status) : body(body), status(status)
{

}

std::string LoadResult::getBody() const
{
    return body;
}

long LoadResult::getStatus() const
{
    return status;  
}