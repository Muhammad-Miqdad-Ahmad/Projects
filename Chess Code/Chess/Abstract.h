#pragma once
#include <string>
class Abstract
{   
public:
    int count;
    virtual bool access(std::string*** board,int index_from_1,int index_from_2,int index_to_1, int index_to_2)  = 0;
    virtual void is_kind_of(std::string) = 0;
    Abstract();
    ~Abstract();
};