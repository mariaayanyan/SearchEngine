#include "CurlException.h"

CurlException::CurlException(const char* msg, int code) : msg(msg), code(code)
{

}

const char* CurlException::getMessage() const
{
    return msg;
}

int CurlException::getCode() const
{
    return code;
}