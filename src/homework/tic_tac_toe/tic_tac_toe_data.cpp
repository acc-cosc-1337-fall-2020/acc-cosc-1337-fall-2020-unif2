//cpp
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include<iostream>
#include<fstream>

void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games)
{
    std::ofstream out_file;//("games.data", std::ios::app);
    out_file.open("games.dat");

    for(auto& game: games)
    {
        for(string& c: game->get_pegs())
        {
            out_file<<c;
        }
        out_file<<game->get_winner()<<std::endl;
    }
    out_file.close();
}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    vector<unique_ptr<TicTacToe>> games;
    
    std::ifstream in_file;
    in_file.open("games.dat");
    
    std::cout<<"Loading saved games...\n";
    string line;
    string winner;
    //vector<string> pegs;

    while(getline(in_file, line))
    {
        vector<string> pegs;
        for(char& c: line.substr(0, line.size()-1))
        {
            pegs.push_back(string(1, c));
        }
        winner = string(1, line[line.size()-1]);
        unique_ptr<TicTacToe> game;

        if(pegs.size() == 9)
        {
            game = make_unique<TicTacToe3>(pegs, winner);
        }
        else if(pegs.size() == 16)
        {
            game = make_unique<TicTacToe4>(pegs, winner);
        }
        games.push_back(std::move(game));
    }
    in_file.close();
    return games;
}