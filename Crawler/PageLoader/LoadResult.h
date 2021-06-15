#ifndef LOAD_RESULT_H
#define LOAD_RESULT_H

#include <string>
#include <memory>

class LoadResult
{
private:
    /**
     * Stores the response body 
     */
    std::shared_ptr<std::string> body;
    
    /**
     * Stores the response status
     */
    long status;

    std::string effectiveUrl;

public:
    LoadResult(std::shared_ptr<std::string> body, int status, const std::string& effectiveUrl = "");
    std::shared_ptr<std::string> getBody() const;
    long getStatus() const;
    std::string getEffectiveUrl() const;
};

#endif 
