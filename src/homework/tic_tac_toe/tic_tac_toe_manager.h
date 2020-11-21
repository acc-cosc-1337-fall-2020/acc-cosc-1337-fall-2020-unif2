//h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#include<iostream>
#include<memory>

class TicTacToeManager
{
    public:
        TicTacToeManager() = default;
        TicTacToeManager(TicTacToeData& d) : data(d){}
        ~TicTacToeManager();
        void save_game(unique_ptr<TicTacToe>& b);
        friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
        void get_winner_total(int& x, int& o, int& t);

    private:
        void update_winner_count(string winner);
        vector<unique_ptr<TicTacToe>> games;
        int x_win{0};
        int o_win{0};
        int ties{0};
        TicTacToeData data;
};
#endif