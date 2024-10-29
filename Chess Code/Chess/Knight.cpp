#include "Header.h"

Knight::~Knight()
{
    if(this->ghora)
    delete[] this->ghora;
    ghora = nullptr;
}

bool Knight::access(string*** board,int index_from_1,int index_from_2,int index_to_1, int index_to_2)
{

    if(index_from_2==index_to_2+1 || index_from_2==index_to_2-1)
    {
        if(index_from_1==index_to_1+2 || index_from_1==index_to_1-2)
            return true;
    }


    if(index_from_2==index_to_2+2 || index_from_2==index_to_2-2)
    {
        if(index_from_1==index_to_1+1 || index_from_1==index_to_1-1)
            return true;
    }

    return false;

}