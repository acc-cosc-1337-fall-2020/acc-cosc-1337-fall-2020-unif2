//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;

class TicTacToe
{
public:
    TicTacToe(vector<string> p, string win) : pegs(p), winner(win){}
    TicTacToe(int size) : pegs(size*size, " "){}
    vector<string> get_pegs()const{return pegs;}
    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    string get_player()const{return player;}
    string get_winner(){return winner;}
    friend std::ostream& operator<<(std::ostream& out, TicTacToe game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

protected:
    vector<string> pegs;
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

private:
    void set_next_player();
    bool check_board_full();
    void clear_board();
    void set_winner();
    string player;
    string winner;
};
#endif