//cpp
#include "tic_tac_toe_manager.h"

TicTacToeManager::TicTacToeManager(TicTacToeData &data)
{
    //Initially, I had vector<unique_ptr<TicTacToe>> games = data.get_games(); but that was causing
    //Previous runtime results to be discarded.
    games = data.get_games();

    for(auto& game: games)
    {
        string winner = game->get_winner();
        update_winner_count(winner);
    }
    int x, o, t;
	get_winner_total(x, o, t);
	std::cout<<"History of results: Player X won "<<x<<" times, Player O won "<<o<<" times, and there have been "<<t<<" ties.\n";
}

TicTacToeManager::~TicTacToeManager()
{
    data.save_games(games);
}

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& b)
{
    update_winner_count(b->get_winner());
    games.push_back(std::move(b));
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    out<<"\nHere are the results of the "<<manager.games.size()<<" games played so far.\n\n";
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