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

public:
    LoadResult(std::shared_ptr<std::string> body, int status);
    std::shared_ptr<std::string> getBody() const;
    long getStatus() const;
};

#endif 
