#include "game.h"

Game::Game(Piece &white, Piece &black)
{
    this->white = &white;
    this->black = &black;
    array = new string **[8]; // ?double pointer ko assign kiya
    for (size_t i = 0; i < 8; i++)
    {
        array[i] = new string *[8]; // ?phir 2 d array bnai
        for (int j = 0; j < 8; j++)
        {
            if (i != 0 && i != 1 && i != 6 && i != 7) // ?in rows main hm ne pieces rakhne hain is liye allocate nahi ki space
                array[i][j] = new string[1];          // ?yahhaan pe mn ne 2d pointer array bna li he and us ko ik space assign kr di
        }
    }
    create_board();
}

Game::~Game()
{
    white = nullptr;
    black = nullptr;
    for (size_t i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (*this->array[i][j] != "  ")
                this->array[i][j] = nullptr;
            else
            {
                delete[] this->array[i][j];
                this->array[i][j] = nullptr;
            } // delete and delete[] main ye faraq hota he k
            // delete[] ik eese space ko delete krta he jo k new string [size] kr k allocate hoti he. jo new string kr k allocate ho wo delete se hoti de del
        }
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
}

void Game::print_line(string color1, string color2, string colorn1, string colorn2, int fix)
{
    for (int j = 0; j < 3; j++)
    {
        if (j == 1)
            cout << "\t\t\t" << chess::bluen << fix + 1 << " " << chess::bluen;
        else
            cout << "\t\t\t" << chess::blues;

        for (int i = 0; i < 8; i++)
        {
            if (j == 1)
            {
                if (i % 2 == 0)
                {
                    if (*(this->array[fix][i]) == "  ")
                        cout << color1;
                    else
                        cout << colorn1 << *(this->array[fix][i]) << colorn1;
                }
                else
                {
                    if (*(this->array[fix][i]) == "  ")
                        cout << color2;
                    else
                        cout << colorn2 << *(this->array[fix][i]) << colorn2;
                }
            }
            else
            {
                if (i % 2 == 0)
                    cout << color1;
                else
                    cout << color2;
            }
        }
        cout << chess::blues << endl;
    }
}

void Game::print_board()
{
    system("clear");
    char letters[] = "abcdefgh";
    for (int i = 0; i < 3; i++)
    {
        cout << "\t\t\t      ";
        for (int j = 0; j < 8; j++)
        {
            if (i == 1)
                cout << chess::bluen << letters[j] << " " << chess::bluen;
            else
                cout << chess::blues;
        }
        cout << endl;
    }
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            print_line(chess::white, chess::black, chess::whiten, chess::blackn, i);
        }
        else
        {
            print_line(chess::black, chess::white, chess::blackn, chess::whiten, i);
        }
    }
    for (int j = 0; j < 3; j++)
    {
        cout << "\t\t\t      ";
        for (int i = 0; i < 8; i++)
        {
            cout << chess::blues;
        }
        cout << endl;
    }
}

void Game::create_board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i != 0 && i != 1 && i != 6 && i != 7) // in rows main hm ne pieces rakhne hain is liye allocate nahi ki space
                *(array[i][j]) = "  ";                // hoa yoon he k do pointers array bna rahe hain. and tesre pointer ki value main mn ne empty space rakh di he
        }
    }

    relations::digit_map[0] = 7; // this is a map defined in the relations namespace in the header.h file
    relations::digit_map[1] = 6; // choon k board pe 0 and 7 index pe same piece hota he is liye and 1 6 pe same hota and 2 5 pe bhi
    relations::digit_map[2] = 5;
    relations::digit_map[3] = 4;
    for (int i = 0; i < 8; i++)
    {
        array[1][i] = white->pawn[i].pyada;
        array[6][i] = black->pawn[i].pyada;
    }
    for (int i = 0; i < 4; i++) // ye wala loop na jahaan jahaan pe hm ne pieces rakhne hain un ko del kr deta hee and
    {
        if (i == 0)
        { // and then main un main according to the board chezeen place kr deta hoon.
            // map dekheen thora samajh aae ga
            array[0][i] = white->rook[0].qila;
            array[0][relations::digit_map[i]] = white->rook[1].qila;
            array[7][i] = black->rook[0].qila;
            array[7][relations::digit_map[i]] = black->rook[1].qila;
        }
        else if (i == 1)
        {
            array[0][i] = white->knight[0].ghora;
            array[0][relations::digit_map[i]] = white->knight[1].ghora;
            array[7][i] = black->knight[0].ghora;
            array[7][relations::digit_map[i]] = black->knight[1].ghora;
        }
        else if (i == 2)
        {
            array[0][i] = white->bishop[0].vazeer;
            array[0][relations::digit_map[i]] = white->bishop[1].vazeer;
            array[7][i] = black->bishop[0].vazeer;
            array[7][relations::digit_map[i]] = black->bishop[1].vazeer;
        }
        else
        {
            array[0][i] = white->king.badsha;
            white->king.row = 0;
            white->king.colomn = i;
            array[0][relations::digit_map[i]] = white->queen.rani;
            array[7][i] = black->king.badsha;
            black->king.row = 7;
            black->king.colomn = i;
            array[7][relations::digit_map[i]] = black->queen.rani;
        }
    }
}

string Game::move(string kin)
{
    relations::letter_map['a'] = 0;
    relations::letter_map['b'] = 1;
    relations::letter_map['c'] = 2;
    relations::letter_map['d'] = 3;
    relations::letter_map['e'] = 4;
    relations::letter_map['f'] = 5;
    relations::letter_map['g'] = 6;
    relations::letter_map['h'] = 7;
    relations::chess_digit_map['1'] = 0;
    relations::chess_digit_map['2'] = 1;
    relations::chess_digit_map['3'] = 2;
    relations::chess_digit_map['4'] = 3;
    relations::chess_digit_map['5'] = 4;
    relations::chess_digit_map['6'] = 5;
    relations::chess_digit_map['7'] = 6;
    relations::chess_digit_map['8'] = 7;
    string input_from, input_to;
    while (true)
    {
        if (kin == "W")
            cout << "This is blue's turn to play\n";
        else
            cout << "This is red's turn to play\n";

        cout << "\nEnter the piece you want to move: ";
        cin >> input_from;
        cout << "Enter where you want to move it: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input_to;
        if (input_from == "abort")
            return input_from;
        else if(input_to == "abort")
            return input_to;
        cout << "You moved a piece from " << input_from << " to " << input_to << endl;
        system("cmd /C pause");
        if (to_move(input_from, kin))
        {
            if (move_to(input_to, input_from, kin))
            {
                cout << "\nThe piece has moved\n\n";
                return "";
            }
            else
            {
                insults();
                system("cmd /C pause");
                continue;
            }
        }
        else
        {
            insults();
            system("cmd /C pause");
            continue;
        }
    }
}

void Game::insults()
{
    srand(time(0));
    int num = (rand() % 10);
    if (num == 0)
    {
        cout << "\nI mean seriously\nLike literally\nyou are really bad at this 😒\n\n\n";
    }
    else if (num == 1)
    {
        cout << "\nOh come on\nCant you see what you are doing\n\n\n";
    }
    else if (num == 2)
    {
        cout << "\nWho gave this man the consol 🤦🏻‍♂️\nSome one please take it from him 😭\nI cant handle it for much longer 😭\n\n\n";
    }
    else if (num == 3)
    {
        cout << "\nOOOOKAY\nI cant even compile this one\n\n\n";
    }
    else if (num == 4)
    {
        cout << "\nI have no words for this 😶\n\n\n";
    }
    else if (num == 5)
    {
        cout << "\nSo whats gonna be your next move\n9 11 ????\n\n\n";
    }
    else if (num == 6)
    {
        cout << "\nThis aint chess anymore 😭\n\n\n";
    }
    else if (num == 7)
    {
        cout << "\nIf you are a chess player then I am a fully automated chess AI that just beat stockfish\n\n\n";
    }
    else if (num == 8)
    {
        cout << "\nCan I have another player 😭\nI dont wanna play with him anymore please\n\n\n";
    }
    else
    {
        cout << "\nThis man should be sentenced to ten years of of prinson\nWith hard labor due to his crimes against chess 😠\n\n\n";
    }
}

bool Game::to_move(string input_from, string kind)
{
    if (valid_move(input_from))
    {
        if (*array[relations::chess_digit_map[input_from[1]]][relations::letter_map[input_from[0]]] != "  ") //! checks if the space jo app hilane ki try kr rahe hain khali he ya nahi
        {
            if (*(array[relations::chess_digit_map[input_from[1]]][relations::letter_map[input_from[0]]] + 1) == kind) //! checks if the space jo app hilane ki try kr rahe hain khali he ya nahi
            {
                return true;
            }
            else
            {
                cout << "\nYou are not suppossed to move this piece 😭";
                return false;
            }
        }
        else
        {
            cout << "\nThis is an empty space 😒";
            return false;
        }
    }
    else
        return false;
    return false;
}

bool Game::move_to(string input_to, string input_from, string kin)
{
    Abstract *abstract;
    if (valid_move(input_to))
    {
        abstract = piece_type(*(array[relations::chess_digit_map[input_from[1]]][relations::letter_map[input_from[0]]]));
        if (abstract->access(array, relations::chess_digit_map[input_from[1]], relations::letter_map[input_from[0]], relations::chess_digit_map[input_to[1]], relations::letter_map[input_to[0]])) //! agar access main aata ho ga to ye run ho jae ga
        {
            if (*(array[relations::chess_digit_map[input_to[1]]][relations::letter_map[input_to[0]]]) == "  ") // agat jahaan move kiya he wo empty space ho to swap ho jae ga
            {
                swap(array[relations::chess_digit_map[input_to[1]]][relations::letter_map[input_to[0]]], array[relations::chess_digit_map[input_from[1]]][relations::letter_map[input_from[0]]]);
                return true;
            }
            else if (*(array[relations::chess_digit_map[input_to[1]]][relations::letter_map[input_to[0]]]) != "  ")
            {
                // check if the piece is white or black and the one to move is white or black.
                if (*(array[relations::chess_digit_map[input_to[1]]][relations::letter_map[input_to[0]]] + 1) == *(array[relations::chess_digit_map[input_from[1]]][relations::letter_map[input_from[0]]] + 1)) //! agar donoon k same hain to invalid move. agar nahi han different hain to aaho
                {
                    cout << "\t\t\t\nThe move is invalid\nThere is another piece of the same type on this tile";
                    return false;
                }
                else // agar wo same nahi hain to kill ka koi function call ho ga
                {
                    kill(relations::chess_digit_map[input_to[1]], relations::letter_map[input_to[0]]);
                    cout << "\nYou just murdered something\n\n";
                    swap(array[relations::chess_digit_map[input_to[1]]][relations::letter_map[input_to[0]]], array[relations::chess_digit_map[input_from[1]]][relations::letter_map[input_from[0]]]);
                    return true;
                }
            }
        }
        else // ni to ye print ho je ga
        {
            cout << "\t\t\t\nThis piece cant move here 😒 ";
            return false;
        }
    }
    else // agar move valid nahi to ye print ho ga
    {
        return false;
    }
    return false;
}

bool Game::valid_move(string move)
{
    char characters[] = "abcdefgh";
    char integers[] = "12345678";
    for (int i = 0; i < 8; i++)
    {
        if (move[0] == characters[i])
        {
            for (int j = 0; j < 8; j++)
            {
                if (move[1] == integers[j])
                {
                    if (move[2] == '\0')
                    {
                        return true;
                    }
                    else
                    {
                        cout << "\nWhat the hell is this third input\nYou were suppossed to only give two input\nSeriously you cant even do this\n\n";
                        return false;
                    }
                }
                else if (j == 7)
                {
                    cout << "\nCOME ON. THIS GOES OFF THE BOARD 😭\n";
                    return false;
                }
            }
        }
    }
    cout << "\nDUDEEEEE. WHERE YOU WANNA TAKE THE PIECE\nTO OUTER SPACE???\n";
    return false;
}

void Game::game_play()
{
    print_board();
    while (true)
    {
        string check;
        cout << endl
             << endl;
        check = move(white->kind);
        if (check == "abort")
            return;
        cout << endl
             << endl;
        print_board();
        // if (this->array[this->black->king.row][this->black->king.colomn] != this->black->king.badsha) // !check_mate function();
        // {
        //     cout << "\nBlack king is dead\n";
        //     this->black->data->person->losses++;
        //     this->white->data->person->wins++;
        //     system("cmd /C pause");
        //     break;
        // }

        ////the end of the first turn

        cout << endl
             << endl;
        check = move(black->kind);
        if (check == "abort")
            return;
        cout << endl
             << endl;
        print_board();
        // if (this->array[this->black->king.row][this->black->king.colomn] != this->white->king.badsha) // !check_mate function();
        // {
        //     cout << "\nWhite King is dead";
        //     this->white->data->person->losses++;
        //     this->black->data->person->wins++;
        //     system("cmd /C pause");
        //     break;
        // }
    }
}

void Game::swap(string *&a, string *&b)
{
    string *temp;
    temp = a;
    a = b;
    b = temp;
}

void Game::kill(int row, int colomn)
{
    this->array[row][colomn] = nullptr;
    this->array[row][colomn] = new string[1];
    *this->array[row][colomn] = "  ";
}

Abstract *Game::piece_type(string &piece)
{
    relations::pointer_map[chess::black_n_white_pieces[0]] = &white->king;
    relations::pointer_map[chess::black_n_white_pieces[1]] = &white->queen;
    relations::pointer_map[chess::black_n_white_pieces[2]] = white->rook;
    relations::pointer_map[chess::black_n_white_pieces[3]] = white->knight;
    relations::pointer_map[chess::black_n_white_pieces[4]] = white->bishop;
    relations::pointer_map[chess::black_n_white_pieces[5]] = white->pawn;
    relations::pointer_map[chess::black_n_white_pieces[6]] = &black->king;
    relations::pointer_map[chess::black_n_white_pieces[7]] = &black->queen;
    relations::pointer_map[chess::black_n_white_pieces[8]] = black->rook;
    relations::pointer_map[chess::black_n_white_pieces[9]] = black->knight;
    relations::pointer_map[chess::black_n_white_pieces[10]] = black->bishop;
    relations::pointer_map[chess::black_n_white_pieces[11]] = black->pawn;
    for (int i = 0; i < 12; i++)
    {
        if (chess::black_n_white_pieces[i] == piece)
        {
            if (chess::black_n_white_pieces[5] == piece && *((&piece) + 1) == "W")
            {
                for (int i = 0; i < 8; i++)
                {
                    if (&piece == white->pawn[i].pyada)
                        return &white->pawn[i];
                }
            }
            else if (chess::black_n_white_pieces[11] == piece && *((&piece) + 1) == "B")
            {
                for (int i = 0; i < 8; i++)
                {
                    if (&piece == black->pawn[i].pyada)
                        return &black->pawn[i];
                }
            }
            else
                return relations::pointer_map[chess::black_n_white_pieces[i]];
        }
    }
    return nullptr;
}

void Game::recreate(Piece &white, Piece &black)
{
    this->~Game();
    this->white = &white;
    this->black = &black;
    array = new string **[8]; // ?double pointer ko assign kiya
    for (size_t i = 0; i < 8; i++)
    {
        array[i] = new string *[8]; // ?phir 2 d array bnai
        for (int j = 0; j < 8; j++)
        {
            if (i != 0 && i != 1 && i != 6 && i != 7) // ?in rows main hm ne pieces rakhne hain is liye allocate nahi ki space
                array[i][j] = new string[1];          // ?yahhaan pe mn ne 2d pointer array bna li he and us ko ik space assign kr di
        }
    }
    create_board();
}
