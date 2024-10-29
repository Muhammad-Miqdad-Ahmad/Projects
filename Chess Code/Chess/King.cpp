#include "Header.h"

King::~King()
{
    if(this->badsha)
    delete[] this->badsha;
    this->badsha = nullptr;
}

bool King::access(string*** board,int from_index_row,int from_index_colomn,int index_to_1, int index_to_2)
{
    bool access = false;
    if(from_index_row>-1)
    {
        if(from_index_row+1==index_to_1&&from_index_colomn==index_to_2)
            access = true;
    }
    if(from_index_row<8)
    {        
        if(from_index_row-1==index_to_1&&from_index_colomn==index_to_2)
            access = true;
    }
    if(from_index_colomn>-1)
    {
        if(from_index_colomn+1==index_to_2&&from_index_row==index_to_1)
            access = true;
    }
    if(from_index_colomn<8)
    {        
        if(from_index_colomn-1==index_to_2&&from_index_row==index_to_1)
            access = true;
    }
    if(from_index_row>-1&&from_index_colomn>-1)
    {
        if(index_to_1==from_index_row-1&&from_index_colomn-1==index_to_2)
            access = true;
    }
    if(from_index_row<8&&from_index_colomn<8)
    {
        if(index_to_1==from_index_row+1&&from_index_colomn+1==index_to_2)
            access = true;
    }
    if(from_index_row<8&&from_index_colomn>-1)
    {
        if(index_to_1==from_index_row+1&&from_index_colomn-1==index_to_2)
            access = true;
    }
    if(from_index_row<8&&from_index_colomn>-1)
    {
        if(index_to_1==from_index_row-1&&from_index_colomn+1==index_to_2)
            access = true;
    }
    if(access)
    {
        this->row = index_to_1;
        this->colomn = index_to_2;
    }
    return access;
}

