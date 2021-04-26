#include "PageLoader.h"
#include "CurlException.h"

#include <curl/curl.h>

#include <errno.h>
#include <iostream>

size_t PageLoader::getData(char* buffer, size_t itemSize, size_t itemCount, void* dest)
{
    size_t bytes = itemSize * itemCount;
    std::string* str = (std::string*)dest;
    str->append(buffer, bytes);
    return bytes;
}

LoadResult PageLoader::load(const std::string& url)
{
    try
    {
        // initialize CURL
        CURL* curl = curl_easy_init();

        if(!curl)
            throw CurlException("Failed to initialize curl", -1);

        std::string* contents = new std::string;

        // set options
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)contents);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 3);

        // connect to the url and download its' contents ы
        CURLcode result = curl_easy_perform(curl);

        if(result != CURLE_OK)
            throw CurlException(curl_easy_strerror(result), result);

        long curlinfoResponseCode;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &curlinfoResponseCode);

        curl_easy_cleanup(curl);
        return LoadResult(std::shared_ptr<std::string>(contents), curlinfoResponseCode);
    } 

    catch(const CurlException& exception)
    {
        std::string* err = new std::string(exception.getMessage());
        return LoadResult(std::shared_ptr<std::string>(err), exception.getCode());
    }
}   
