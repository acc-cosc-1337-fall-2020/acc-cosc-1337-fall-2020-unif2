//cpp
#include "tic_tac_toe.h"
#include<iostream>
using std::cout;
using std::cin;

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    //TicTacToe::clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    TicTacToe::set_next_player();
    //Commenting out code added due to previous version of instructions.
    /*if(!game_over())
    {
        TicTacToe::set_next_player();
    }*/
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
{   //Here, even if winner wins and fills the board on the last move, this statement will be true.
    if(check_column_win() || check_row_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    //If function reaches this, then previous statement was false, so if board is full, then the game must have ended in a tie.
    else if(TicTacToe::check_board_full())
    {
        winner = "C";
        return true;
    }
    //Here, nobody has won and the board is not full, so game is not over yet.
    else
    {
        return false;
    }
    
}

bool TicTacToe::check_column_win()
{
    return false;
}

bool TicTacToe::check_row_win()
{
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}

void TicTacToe::set_winner()
{   
    if(player == "X")
    {
        winner = "O";//From previous version of instructions, this was "X"
    }
    else
    {
        winner = "X";//From previous version of instructions, this was "O"
    }
}

std::ostream& operator<<(std::ostream& out, const TicTacToe game)
{
    int size = game.pegs.size();
    string border(size*2 - 1, '_');

    for(std::size_t i=0; i < size; ++i)
    {
        out<<game.pegs[i];
        if((i+1) % size != 0)
        {
            out<<"|";
        }

        if((i+1) % size == 0 && i != size-1)
        {
            out<<border;
        }
    }
    
    /*for(std::size_t i=0; i < game.pegs.size(); ++i)
    {
        out<<game.pegs[i];
        if((i+1) % 3 == 1 || (i+1) % 3 == 2)
        {
            out<<"|";
        }

        if((i+1) % 3 == 0 && i != 8)
        {
            out<<"\n_____\n";
        }
    }*/
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    double pos;
	cout<<"\n\nPlayer "<<game.get_player()<<", it's your turn.\n";
	cout<<"Choose your position (integer between 1 and "<<game.pegs.size()<<") and DO NOT pick one that's already being occupied! ";
	in>>pos;
	while(pos < 1 || pos > game.pegs.size())
	{
		cout<<"\nInvalid entry! Position must be an integer between 1 and "<<game.pegs.size()<<" and not already occupied.\n";
		cout<<"Choose your position: ";
		in>>pos;
	}
	int position = pos;
	game.mark_board(position);
    return in;
}