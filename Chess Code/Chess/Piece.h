#pragma once
#include "Header.h"

class Piece
{
public:
    string kind;
    DataBase *data;
    King king;
    Queen queen;
    Bishop *bishop = new Bishop[2];
    Rook *rook = new Rook[2];
    Knight *knight = new Knight[2];
    Pawn *pawn = new Pawn[8];
    Piece(int num, string kind, DataBase *data);
    bool check(string ***board, int from_index_row, int from_index_colomn, string kin);
    ~Piece();
};