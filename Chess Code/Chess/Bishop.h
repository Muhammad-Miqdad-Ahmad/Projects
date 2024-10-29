#pragma once
#include <iostream>
#include "Abstract.h"
using namespace std;

class Bishop:public Abstract//The class that is responsible for the class of the Bishop piece
{
private:
    
public://ye mn ne kuch bhi q kiya he us ki explaination king.h main he
    void is_kind_of(string kind)
    {
        this->vazeer[1] = kind;
    }
    string *vazeer;
    bool access(string*** board,int index_from_1,int index_from_2,int index_to_1, int index_to_2) override;
    Bishop() {
        this->count=0;
        this->vazeer = new string[2];
    };
    ~Bishop();
};




