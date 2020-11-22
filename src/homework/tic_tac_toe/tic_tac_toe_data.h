//h
#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

#include "tic_tac_toe.h"
#include<memory>
using std::unique_ptr; using std::make_unique;

class TicTacToeData
{
    public:
        void save_games(const vector<unique_ptr<TicTacToe>>& games);
        vector<unique_ptr<TicTacToe>> get_games();

};

#endif