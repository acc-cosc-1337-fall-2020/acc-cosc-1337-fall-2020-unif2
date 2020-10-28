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

bool TicTacToe::game_over()
{   //Even if winner wins and fills the board on the last move, this statement will be true.
    if(TicTacToe::check_column_win() || TicTacToe::check_row_win() || TicTacToe::check_diagonal_win())
    {
        set_winner();
        return true;
    }
    //Previous statement here, so if board is full, then the game ends in a tie.
    else if(TicTacToe::check_board_full())
    {
        winner = "C";
        return true;
    }
    //Nobody has won and the board is not full, so game is not over yet.
    else
    {
        return false;
    }
    
}

bool TicTacToe::check_column_win()
{   //0,3,6 or 1,4,7 or 2,5,8
    for(std::size_t i=0; i < pegs.size()/3; ++i)
    {
        if((pegs[i] == pegs[i+3]) && (pegs[i] == pegs[i+6]) && (pegs[i] != " "))
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_row_win()
{   //1,2,3 or 4,5,6 or 7,8,9
    for(std::size_t i=0; i < pegs.size()/3; ++i)
    {
        if((pegs[3*i] == pegs[3*i+1]) && (pegs[3*i] == pegs[3*i+2] && (pegs[3*i] != " ")))
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win()
{   //0,4,8 or 2,4,6
    if((pegs[0] == pegs[4]) && (pegs[0] == pegs[8]) && (pegs[0] != " "))
    {
        return true;
    }

    else if((pegs[2] == pegs[4]) && (pegs[2] == pegs[6]) && (pegs[2] != " "))
    {
        return true;
    }
    return false;
}

void TicTacToe::set_winner()
{   //O made the winning move, so player is set to X. Otherwise, X made the winning move.
    if(player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
}