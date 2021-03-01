#include "PageLoader.h"

#include <curl/curl.h>

#include <errno.h>
#include <iostream>
#include <fstream>
#include <sstream>

size_t getData(char* buffer, size_t itemSize, size_t itemCount)
{
    size_t bytes = itemSize * itemCount;
   
    std::ofstream out("Result.txt");
    out.write(buffer, bytes);
    out.close();
   
    return bytes;
}

LoadResult PageLoader::load(const std::string& url)
{
    // initialize CURL
    CURL* curl = curl_easy_init();

    if(!curl)
    {
        perror("Init failed");
        exit(-1);
    }

    // set options
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getData);
    
    // connect to the url and download its' contents 
    CURLcode result = curl_easy_perform(curl);

    if(result != CURLE_OK)
    {
        perror("Download problem");
        exit(result);
    }

    long curlinfoResponseCode;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, curlinfoResponseCode);

    // get contents from file
    std::ifstream in("Result.txt");
    std::ostringstream oss;
    oss << in.rdbuf();
    in.close();
    std::string contents(oss.str());
    remove("Result.txt");

    curl_easy_cleanup(curl);
    return LoadResult(contents, curlinfoResponseCode);
}
