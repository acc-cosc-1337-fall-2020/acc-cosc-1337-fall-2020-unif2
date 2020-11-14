//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& b)
{
    update_winner_count(b->get_winner());
    games.push_back(std::move(b));
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    out<<"\nHere are the results of the "<<manager.games.size()<<" games played.\n\n";
    for(auto& g: manager.games)
    {
        out<<*g;
        out<<"\n\n\n";
    }
    return out;
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;
    //std::cout<<"Player X wins "<<x_win<<" times, Player O wins "<<o_win<<" times, and there are "<<ties<<" ties.\n";
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