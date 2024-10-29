#pragma once
#include <iostream>
#include "Abstract.h"
using namespace std;

class Queen:public Abstract//The class that is responsible for the class of the Queen piece
{
private:
     
public://ye mn ne kuch bhi q kiya he us ki explaination king.h main he
    string *rani;
    void is_kind_of(string kind)
    {
        this->rani[1] = kind;
    }
     bool access(string*** board,int index_from_1,int index_from_2,int index_to_1, int index_to_2) override;
    Queen() 
    {
        this->count=0;
        this->rani = new string[2];
    };
    ~Queen();
};




