//h
#include "tic_tac_toe.h"
#include<iostream>
#include<memory>

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H 

class TicTacToeManager
{
    public:
        void save_game(std::unique_ptr<TicTacToe>& b);
        friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
        void get_winner_total(int& x, int& o, int& t);

    private:
        void update_winner_count(string winner);
        vector<std::unique_ptr<TicTacToe>> games;
        int x_win{0};
        int o_win{0};
        int ties{0};
};
#endif