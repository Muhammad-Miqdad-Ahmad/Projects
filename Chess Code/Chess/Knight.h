#pragma once
#include <iostream>
#include "Abstract.h"
using namespace std;

class Knight: public Abstract // The class that is responsible for the class of the Knight piece
{
private:
public://ye mn ne kuch bhi q kiya he us ki explaination king.h main he
    void is_kind_of(string kind)
    {
        this->ghora[1] = kind;
    }
    string *ghora;
    bool access(string*** board,int index_from_1,int index_from_2,int index_to_1, int index_to_2) override;
    Knight() {
        this->count=0;
        this->ghora = new string[2];
    };
    ~Knight();
};