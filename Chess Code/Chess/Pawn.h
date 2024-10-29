#pragma once
#include <iostream>
#include "Abstract.h"
using namespace std;

class Pawn:public Abstract//The class that is responsible for the class of the Pawns piece
{
private:
public://ye mn ne kuch bhi q kiya he us ki explaination king.h main he

    string *pyada;
    void is_kind_of(string kind)
    {
        this->pyada[1] = kind;
    }
    bool access(string*** board,int index_from_1,int index_from_2,int index_to_1, int index_to_2) override;
    Pawn() {
        this->count = 0;
        this->pyada = new string[2];
    };
    ~Pawn();
};




