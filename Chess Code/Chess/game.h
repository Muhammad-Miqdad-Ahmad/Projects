#pragma once
#include "Piece.h"

class Game
{
private:
    static Game *instance;
    Piece *white;
    Piece *black;
    Game(Piece &, Piece &);
    string ***array; // ?triple pointer bnaya he mn ne
    Game() = delete;
    Game(const Game &data) = delete;

public:
    ~Game();
    static Game *get_instance(Piece &player1, Piece &player2)
    {
        if (instance == nullptr)
        {
            instance = new Game(player1, player2);
        }
        return instance;
    }
    static void release_instance()
    {
        if(instance != nullptr)
            instance = nullptr;
    }
    void print_line(string color1, string color2, string colorn1, string colorn2, int fix);
    void print_board();
    void create_board();
    void swap(string *&a, string *&b);
    string move(string kind);
    bool to_move(string input_from, string kind);
    bool move_to(string input_to, string,string);
    void insults();
    void game_play();
    bool valid_move(string move);
    void kill(int row, int colomn);
    Abstract *piece_type(string &piece);
    void recreate(Piece &white, Piece &black);
};