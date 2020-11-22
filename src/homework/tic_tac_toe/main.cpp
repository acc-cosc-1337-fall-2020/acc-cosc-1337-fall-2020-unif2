#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include<memory>
#include<iostream>
using std::cout;
using std::cin;
using std::unique_ptr;
using std::make_unique;
int main() 
{
	string player;
	TicTacToeData data;
	TicTacToeManager manager(data);
	char choice;
	do
	{
		unique_ptr<TicTacToe> game;
		double num;
		int x, o, t;
		manager.get_winner_total(x, o, t);
		cout<<"Game "<<x+o+t+1<<"\n";
		cout<<"Enter 3 for TicTacToe3 or 4 for TicTacToe4: ";
		cin>>num;
		while((num != 3) && (num != 4))
		{
			cout<<"\nInvalid entry!  Please choose either 3 or 4: ";
			cin>>num;
		}
		
		int version = num;

		if(version == 3)
		{
			game = make_unique<TicTacToe3>();
		}
		else
		{
			game = make_unique<TicTacToe4>();
		}
		
		cout<<"\nFirst player, choose either X or O: ";
		cin>>player;

		while (player != "X" && player != "O")
		{
			cout<<"\nInvalid entry!  Please enter either X or O: ";
			cin>>player;
		}
		
		game->start_game(player);
		cout<<"\nHere is the current board state: \n\n";
		cout<<*game;

		while(!game->game_over())
		{
			cin>>*game;
			cout<<"\nHere is the current board state:\n\n";
			cout<<*game;
		}

		if(game->get_winner() == "C")
		{
			cout<<"\n\nHere is the final board state. It's a TIE!\n";
			cout<<*game<<"\n\n";
		}

		else
		{
			cout<<"\n\nHere is the final board state. Player "<<game->get_winner()<<" wins!\n\n";
			cout<<*game<<"\n\n";
		}
		manager.save_game(game);
		manager.get_winner_total(x, o, t);
		cout<<"Results so far: Player X wins "<<x<<" times, Player O wins "<<o<<" times, and there are "<<t<<" ties.\n";
		cout<<"Enter y to play another game, or any other key to quit: ";
		cin>>choice;
	} while(choice == 'y' || choice == 'Y');
	cout<<manager;
	cout<<"Saving games to file.\n";

return 0;
}