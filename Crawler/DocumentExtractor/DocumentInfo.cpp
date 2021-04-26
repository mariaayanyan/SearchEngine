#include "DocumentInfo.h"

DocumentInfo::DocumentInfo(const std::string& text, const std::string& title, const std::string& description) 
                                    : text(text), title(title), description(description)
{
    
}


std::string DocumentInfo::getText() const
{
    return text;
}
std::string DocumentInfo::getTitle() const
{
    return title;
}
std::string DocumentInfo::getDescription() const
{
    return description;
}
