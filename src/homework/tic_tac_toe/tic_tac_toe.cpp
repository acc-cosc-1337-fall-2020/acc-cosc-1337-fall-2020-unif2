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
    if(!game_over())
    {
        TicTacToe::set_next_player();
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
{   //Here, even if winner wins and fills the board on the last move, this statement will be true.
    if(TicTacToe::check_column_win() || TicTacToe::check_row_win() || TicTacToe::check_diagonal_win())
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
{   //0,1,2 or 3,4,5 or 6,7,8
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
{   
    if(player == "X")
    {
        winner = "X";
    }
    else
    {
        winner = "O";
    }
}

std::ostream& operator<<(std::ostream& out, const TicTacToe game)
{
    game.display_board();
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    double pos;
	cout<<"\n\nPlayer "<<game.get_player()<<", it's your turn.\n";
	cout<<"Choose your position (integer between 1 and 9) and DO NOT pick one that's already being occupied! ";
	in>>pos;
	while(pos < 1 || pos > 9)
	{
		cout<<"\nInvalid entry! Position must be an integer between 1 and 9 and not already occupied.\n";
		cout<<"Choose your position: ";
		in>>pos;
	}
	int position = pos;
	game.mark_board(position);
    return in;
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