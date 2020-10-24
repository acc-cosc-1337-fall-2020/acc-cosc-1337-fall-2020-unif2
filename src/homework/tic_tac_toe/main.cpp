#include "tic_tac_toe.h"
#include<iostream>
using std::cout;
using std::cin;
int main() 
{
string player;
TicTacToe game;

cout<<"Tic Tac Toe!  First player, choose either X or O: ";
cin>>player;

while (player != "X" && player != "O")
{
	cout<<"\nInvalid entry!  Please enter either X or O: ";
	cin>>player;
}

cout<<"\nHere is the current board state: \n\n";
game.display_board();

game.start_game(player);
double pos;
while(!game.game_over())
{
	cout<<"\n\nPlayer "<<game.get_player()<<", it's your turn.\n";
	cout<<"Choose your position (integer between 1 and 9) and DO NOT pick one that's already being occupied! ";
	cin>>pos;
	while(pos < 1 || pos > 9)
	{
		cout<<"\nInvalid entry! Position must be an integer between 1 and 9 and not already occupied.\n";
		cout<<"Choose your position: ";
		cin>>pos;
	}
	int position = pos;
	game.mark_board(position);
	cout<<"\nHere is the current board state:\n\n";
	game.display_board();
}
cout<<"\n\nHere is the final board state. Figure out who won!  Thanks for playing!\n\n";
game.display_board();
cout<<"\n";

return 0;
}