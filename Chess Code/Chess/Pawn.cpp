#include "Header.h"

Pawn::~Pawn()
{
    if(this->pyada)
    delete[] this->pyada;
    this->pyada = nullptr;
}

bool Pawn::access(string ***board, int index_from_1, int index_from_2, int index_to_1, int index_to_2) {
    int num;
    if (this->count == 0)
        num = 1;
    else
        num = 0;
    if (*(board[index_from_1][index_from_2] + 1) == "W") {
        //for white pawn

        if(index_to_1==index_from_1+1&&index_from_2+1==index_to_2)
            return true;

        if(index_to_1==index_from_1+1&&index_from_2-1==index_to_2)
            return true;

        for (int i = index_from_1 + 1; i <= index_from_1 + 1 + num; i++) {
            if (i == index_to_1 && index_from_2 == index_to_2) {
                this->count++;
                return true;
            } else if (*(board[i][index_from_2]) == "  ") {
                continue;
            } else if (*(board[i][index_from_2]) != "  ") {
                break;
            }
        }



    } else {
        //for black pawn

        if(index_to_1==index_from_1-1&&index_from_2+1==index_to_2)
            return true;

        if(index_to_1==index_from_1-1&&index_from_2-1==index_to_2)
            return true;

        for (int i = index_from_1 - 1; i >= index_from_1 - 1 - num; i--) {
            if (i == index_to_1 && index_from_2 == index_to_2) {
                this->count++;
                return true;
            } else if (*(board[i][index_from_2]) == "  ") {
                continue;
            } else if (*(board[i][index_from_2]) != "  ") {
                break;
            }


        }


    }
    return false;
}
