#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include<iostream>
using std::cout;
using std::cin;

int main() 
{
	string player;
	TicTacToe game;
	TicTacToeManager manager;
	char choice;
	do
	{
		cout<<"Tic Tac Toe!  First player, choose either X or O: ";
		cin>>player;

		while (player != "X" && player != "O")
		{
			cout<<"\nInvalid entry!  Please enter either X or O: ";
			cin>>player;
		}
		
		game.start_game(player);
		cout<<"\nHere is the current board state: \n\n";
		cout<<game;

		while(!game.game_over())
		{
			cin>>game;
			cout<<"\nHere is the current board state:\n\n";
			cout<<game;
		}

		if(game.get_winner() == "C")
		{
			cout<<"\n\nHere is the final board state. It's a TIE!\n";
			cout<<game<<"\n\n";
		}

		else
		{
			cout<<"\n\nHere is the final board state. Player "<<game.get_winner()<<" wins!\n\n";
			cout<<game<<"\n\n";
		}

		cout<<"Enter y to play another game, or any other key to quit: ";
		cin>>choice;
	} while(choice == 'y' || choice == 'Y');

return 0;
}