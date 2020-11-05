//h
#include "tic_tac_toe.h"
#include<iostream>

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H 

class TicTacToeManager
{
    public:
        void save_game(const TicTacToe b);
        friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
        void get_winner_total(int& o, int& x, int& t);

    private:
        void update_winner_count(string winner);
        vector<TicTacToe> games;
        int x_win{0};
        int o_win{0};
        int ties{0};
};
#endif