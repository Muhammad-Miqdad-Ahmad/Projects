#pragma once
#include <iostream>
#include "Abstract.h"
using namespace std;

class Rook:public Abstract//The class that is responsible for the class of the Rook piece
{
private:
public://ye mn ne kuch bhi q kiya he us ki explaination king.h main he
    void is_kind_of(string kind)
    {
        this->qila[1] = kind;
    }
    string *qila;
     bool access(string*** board,const int index_from_1,const int index_from_2,const int index_to_1,const int index_to_2)  override;
    Rook() {
        this->count=0;
        this->qila = new string[2];
    };
    ~Rook();
};




