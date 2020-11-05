//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(const TicTacToe b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for(auto& g: games)
    {
        out<<g;
    }
    return out;
}

void TicTacToeManager::get_winner_total(int& o, int& w, int& t)
{

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