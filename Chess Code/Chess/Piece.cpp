#include "Piece.h"

Piece::Piece(int num, string kind, DataBase *data)
{
    this->data = data;
    this->kind = kind;
    *(this->king.badsha) = chess::black_n_white_pieces[num]; // king white
    king.is_kind_of(kind);
    *(this->queen.rani) = chess::black_n_white_pieces[num+1]; // queen white
    queen.is_kind_of(kind);

    for (int i = 0; i < 2; i++)
    {
        *(this->rook[i].qila) = chess::black_n_white_pieces[num+2];      // rook white
        *(this->knight[i].ghora) = chess::black_n_white_pieces[num+3];   // knight white
        *(this->bishop[i].vazeer) = chess::black_n_white_pieces[num+4]; // bishop white
        rook[i].is_kind_of(kind);
        knight[i].is_kind_of(kind);
        bishop[i].is_kind_of(kind);
    }

    for (int i = 0; i < 8; i++)
    {
        *(this->pawn[i].pyada) = chess::black_n_white_pieces[num+5];
        pawn[i].is_kind_of(kind);
    }
}

Piece::~Piece()
{
    data = nullptr;
    delete[] this->pawn;
    this->pawn = nullptr;
    delete[] this->rook;
    this->rook = nullptr;
    delete[] this->knight;
    this->knight = nullptr;
    delete[] this->bishop;
    this->bishop = nullptr;
    delete[] this->pawn;
    this->pawn = nullptr;
}

bool Piece::check(string ***board, int from_index_row, int from_index_colomn, string kin) 
{
    for (int i = from_index_colomn + 1; i < 8; i++) //for rook and queen
    {
        cout << "loop: 1\n";
        if (*(board[from_index_row][i]) == "  ") //if it is empty then it will simply continue
        {
            continue;
        }
        else if (*(board[from_index_row][i]) != "  " && *(board[from_index_row][i]+1)==kin ) //if its not empty and jo piece para he us ki kind bhi king ki kind se different he to ye access ho ga
            break;
        else if (*(board[from_index_row][i]) != "  " && *(board[from_index_row][i]+1)!=kin ) //if its not empty and jo piece para he us ki kind bhi king ki kind se different he to ye access ho ga
        {   //agar jo piece para he straight line main wo rook ya queen ho to its a check;
            if(*(board[from_index_row][i]) == chess::black_n_white_pieces[2] || *(board[from_index_row][i]) == chess::black_n_white_pieces[8] || *(board[from_index_row][i]) == chess::black_n_white_pieces[1] || *(board[from_index_row][i]) == chess::black_n_white_pieces[7])
            {
                return false;
            }
        }
    }
    for (int i = from_index_colomn - 1; i >= 0; i--) //for rook and queen
    {
        cout << "loop: 2\n";
        if (*(board[from_index_row][i]) == "  ") 
        {
            continue;
        }
        else if (*(board[from_index_row][i]) != "  " && *(board[from_index_row][i]+1)==kin )
        break; 
        else if (*(board[from_index_row][i]) != "  " && *(board[from_index_row][i]+1)!=kin ) 
        {
            if(*(board[from_index_row][i]) == chess::black_n_white_pieces[2] || *(board[from_index_row][i]) == chess::black_n_white_pieces[8] || *(board[from_index_row][i]) == chess::black_n_white_pieces[1] || *(board[from_index_row][i]) == chess::black_n_white_pieces[7])
            {
                return false;
            }
        }
    }
    for (int i = from_index_row + 1; i < 8; i++) //for rook and queen
    {
        cout << "loop: 3\n";
        if (*(board[i][from_index_colomn]) == "  ") 
        {
            continue;
        }
        else if (*(board[i][from_index_colomn]) != "  " && *(board[i][from_index_colomn]+1)==kin)
        break; 
        else if (*(board[i][from_index_colomn]) != "  " && *(board[i][from_index_colomn]+1)!=kin) 
        {
            if(*(board[i][from_index_colomn]) == chess::black_n_white_pieces[2] || *(board[i][from_index_colomn])  == chess::black_n_white_pieces[8] || *(board[i][from_index_colomn])  == chess::black_n_white_pieces[1] || *(board[i][from_index_colomn])  == chess::black_n_white_pieces[7])
            {
                return false;
            }
        }
    }
    for (int i = from_index_row - 1; i >= 0; i--) //for rook and queen
    {
        cout << "loop: 4\n";
        if (*(board[i][from_index_row]) == "  ") 
        {
            continue;
        }
        else if (*(board[i][from_index_row]) != "  " && *(board[i][from_index_row]+1) ==kin)
        break; 
        else if (*(board[i][from_index_row]) != "  " && *(board[i][from_index_row]+1) !=kin) 
        {
            if(*(board[i][from_index_row]) == chess::black_n_white_pieces[2] || *(board[i][from_index_row])  == chess::black_n_white_pieces[8] || *(board[i][from_index_row])  == chess::black_n_white_pieces[1] || *(board[i][from_index_row])  == chess::black_n_white_pieces[7])
            {
                return false;
            }
        }
    }
    for (int i = from_index_row + 1, j = from_index_colomn + 1; i < 8 && j < 8; i++, j++) //for bishop and queen
    {
        cout << "loop: 5\n";
        if (*(board[i][j]) == "  ") 
        {
            continue;
        }

        else if (*(board[i][j]) != "  " && *(board[i][j]) == kin)
        break; 
        else if (*(board[i][j]) != "  " && *(board[i][j]) != kin) 
        {   
            if(*(board[i][j]) == chess::black_n_white_pieces[4] || *(board[i][j]) == chess::black_n_white_pieces[1])
            {
                return false;
            }
        }
    }
    for (int i = from_index_row + 1, j = from_index_colomn - 1; i < 8 && j >= 0; i++, j--) //for bishop and queen
    {
        cout << "loop: 6\n";
        if (*(board[i][j]) == "  ") 
        {
            continue;
        }

        else if (*(board[i][j]) != "  " && *(board[i][j]) == kin)
        break; 
        else if (*(board[i][j]) != "  " && *(board[i][j]) != kin) 
        {   
            if(*(board[i][j]) == chess::black_n_white_pieces[4] || *(board[i][j]) == chess::black_n_white_pieces[1])
            {
                return false;
            }
        }
    }
    for (int i = from_index_row - 1, j = from_index_colomn + 1; i >= 0 && j < 8; i--, j++) //for bishop and queen
    {
        cout << "loop: 7\n";
        if (*(board[i][j]) == "  ") 
        {
            continue;
        }

        else if (*(board[i][j]) != "  " && *(board[i][j]) == kin) 
        break;
        else if (*(board[i][j]) != "  " && *(board[i][j]) != kin) 
        {   
            if(*(board[i][j]) == chess::black_n_white_pieces[4] || *(board[i][j]) == chess::black_n_white_pieces[1])
            {
                return false;
            }
        }
    }
    for (int i = from_index_row - 1, j = from_index_colomn - 1; i >= 0 && j >= 0; i--, j--) //for bishop and queen
    {
        cout << "loop: 8\n";
        if (*(board[i][j]) == "  ") 
        {
            continue;
        }

        else if (*(board[i][j]) != "  " && *(board[i][j]) == kin) 
        break;
        else if (*(board[i][j]) != "  " && *(board[i][j]) != kin) 
        {   
            if(*(board[i][j]) == chess::black_n_white_pieces[4] || *(board[i][j]) == chess::black_n_white_pieces[1])
            {
                return false;
            }
        }
    }    
    cout << "It return true\n";
    system("cmd /C pause");
    return true;
}
