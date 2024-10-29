#include "Header.h"

Rook::~Rook()
{
    if(this->qila)
    delete[] this->qila;
    this->qila = nullptr;
}

bool Rook::access(string*** board,const int index_from_1,const int index_from_2,const int index_to_1,const int index_to_2)
{
    //!all way right
    for(int i=index_from_2+1;i<8;i++)
    {
        if(index_from_1==index_to_1 && i==index_to_2)
        {
            return true;
        }

        else if(*(board[index_from_1][i]) == "  ")
        {
            continue;
        }

        else if(*(board[index_from_1][i]) != "  ")
        {
            break;
        }
    }

    //!all way left
    for(int i=index_from_2-1;i>=0;i--)
    {
        if(index_from_1==index_to_1 && i==index_to_2)
        {
            return true;
        }

        else if(*(board[index_from_1][i]) == "  ")
        {
            continue;
        }

        else if(*(board[index_from_1][i]) != "  ")
        {
            break;
        }
    }

    //!all way up
    for(int i=index_from_1+1;i<8;i++)
    {
        if(i==index_to_1 && index_from_2==index_to_2)
        {
            return true;
        }

        else if(*(board[i][index_from_2]) == "  ")
        {
            continue;
        }

        else if(*(board[i][index_from_2]) != "  ")
        {
            break;
        }
    }

    //all way down
    for(int i=index_from_1-1;i>=0;i--)
    {
        if(i==index_to_1 && index_from_2==index_to_2)
        {
            return true;
        }

        else if(*(board[i][index_from_2]) == "  ")
        {
            continue;
        }

        else if(*(board[i][index_from_2]) != "  ")
        {
            break;
        }
    }
    return false;
}