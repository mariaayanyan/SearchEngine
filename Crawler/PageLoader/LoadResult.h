#ifndef LOAD_RESULT_H
#define LOAD_RESULT_H

#include <string>

class LoadResult
{
private:
    /**
     * Stores the response body 
     */
    std::string body;
    
    /**
     * Stores the response status
     */
    long status;

public:
    LoadResult(const std::string& body, int status);
    std::string getBody() const;
    long getStatus() const;
};

#endif 
