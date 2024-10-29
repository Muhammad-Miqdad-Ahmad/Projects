#include "Header.h"

Queen::~Queen()
{
    if(this->rani)
    delete[] this->rani;
    this->rani = nullptr;
}


bool Queen::access(string ***board, int index_from_1, int index_from_2, int index_to_1, int index_to_2) {
    //all way right
    for(int i=index_from_2+1;i<8;i++)
    {
        if(index_from_1==index_to_1 && i==index_to_2)
        {
            return true;
        }

        if(*(board[index_from_1][i]) == "  ")
        {
            continue;
        }

        if(*(board[index_from_1][i]) != "  ")
        {
            break;
        }
    }

//all way left
    for(int i=index_from_2-1;i>=0;i--)
    {
        if(index_from_1==index_to_1 && i==index_to_2)
        {
            return true;
        }

        if(*(board[index_from_1][i]) == "  ")
        {
            continue;
        }

        if(*(board[index_from_1][i]) != "  ")
        {
            break;
        }
    }

    //all way up
    for(int i=index_from_1+1;i<8;i++)
    {
        if(i==index_to_1 && index_from_2==index_to_2)
        {
            return true;
        }

        if(*(board[i][index_from_2]) == "  ")
        {
            continue;
        }

        if(*(board[i][index_from_2]) != "  ")
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

        if(*(board[i][index_from_2]) == "  ")
        {
            continue;
        }

        if(*(board[i][index_from_2]) != "  ")
        {
            break;
        }
    }
    //diagonal up right
    for(int i=index_from_1+1,j=index_from_2+1;i<8 && j<8;i++,j++)
    {
        if(i==index_to_1 && j==index_to_2)
        {
            return true;
        }

        if(*(board[i][j]) == "  ")
        {
            continue;
        }

        if(*(board[i][j]) != "  ")
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

        if(*(board[i][j]) == "  ")
        {
            continue;
        }

        if(*(board[i][j]) != "  ")
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

        if(*(board[i][j]) == "  ")
        {
            continue;
        }

        if(*(board[i][j]) != "  ")
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

        if(*(board[i][j]) == "  ")
        {
            continue;
        }

        if(*(board[i][j]) != "  ")
        {
            break;
        }
    }
    return false;
}
