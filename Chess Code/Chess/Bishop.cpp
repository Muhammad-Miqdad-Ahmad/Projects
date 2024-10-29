#include "Header.h"

Bishop::~Bishop()
{
    if(this->vazeer)
    delete[] this->vazeer;
    this->vazeer = nullptr;
}

bool Bishop::access(string ***board, int index_from_1, int index_from_2, int index_to_1, int index_to_2) {
//diagonal up right
    for(int i=index_from_1+1,j=index_from_2+1;i<8 && j<8;i++,j++)
    {
        if(i==index_to_1 && j==index_to_2)
        {
            return true;
        }

        else if(*(board[i][j]) == "  ")
        {
            continue;
        }

        else if(*(board[i][j]) != "  ")
        {
            break;
        }
    }


//diagonal up left
    for(int i=index_from_1+1,j=index_from_2-1;i<8 && j>=0;i++,j--)
    {
        if(i==index_to_1 && j==index_to_2)
        {
            return true;
        }

        else if(*(board[i][j]) == "  ")
        {
            continue;
        }

        else if(*(board[i][j]) != "  ")
        {
            break;
        }

    }

//diagonal down right
    for(int i=index_from_1-1,j=index_from_2+1;i>=0 && j<8;i--,j++)
    {
        if(i==index_to_1 && j==index_to_2)
        {
            return true;
        }

        else if(*(board[i][j]) == "  ")
        {
            continue;
        }

        else if(*(board[i][j]) != "  ")
        {
            break;
        }

    }

//diagonal down left
    for(int i=index_from_1-1,j=index_from_2-1;i>=0 && j>=0;i--,j--)
    {
        if(i==index_to_1 && j==index_to_2)
        {
            return true;
        }

        else if(*(board[i][j]) == "  ")
        {
            continue;
        }

        else if(*(board[i][j]) != "  ")
        {
            break;
        }
    }
    return false;
}