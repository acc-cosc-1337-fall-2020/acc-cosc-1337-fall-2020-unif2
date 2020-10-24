//cpp
#include "tic_tac_toe.h"
#include<iostream>
using std::cout;
using std::cin;

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    TicTacToe::clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    TicTacToe::set_next_player();
}

void TicTacToe::display_board()const
{
    for(std::size_t i=0; i < pegs.size(); ++i)
    {
        cout<<pegs[i];
        if((i+1) % 3 == 1 || (i+1) % 3 == 2)
        {
            cout<<"|";
        }

        if((i+1) % 3 == 0 && i != 8)
        {
            cout<<"\n_____\n";
        }
    }
}

void TicTacToe::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    }

    else
    {
        player = "X";
    }
    
}

bool TicTacToe::check_board_full()
{
    for(auto i: pegs)
    {
        if(i == " ")
        {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board()
{
    pegs = {" "," "," "," "," "," "," "," "," "};
}
