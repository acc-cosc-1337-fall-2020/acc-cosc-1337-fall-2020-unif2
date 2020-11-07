//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(TicTacToe b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    out<<"\nHere are the results of the "<<manager.games.size()<<" games played.\n\n";
    for(auto& g: manager.games)
    {
        out<<g;
        out<<"\n\n\n";
    }
    return out;
}

void TicTacToeManager::get_winner_total()
{
    std::cout<<"Player X wins "<<x_win<<" times, Player O wins "<<o_win<<" times, and there are "<<ties<<" ties.\n";
}

void TicTacToeManager::update_winner_count(string winner)
{
    if(winner == "X")
    {
        x_win += 1;
    }

    else if(winner == "O")
    {
        o_win += 1;
    }

    else
    {
        ties += 1;
    }
    
}