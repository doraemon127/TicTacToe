/*
  Project Description: This is a program for a two-player Tic-Tac-Toe game in the command line.
  Name: Aammya Sapra
  Date: February 26, 2021
*/

#include <iostream>
#include <cstring>
using namespace std;


char board[3][3] = { { ' ',' ',' ' },{ ' ',' ',' ' },{ ' ',' ',' ' } }; //game board
char empty = ' ';
char player_X = 'X';
char player_O = 'O';


//function prototypes
void print_board(); 
bool check_win(char player); 
bool check_tie();


//main
int main() {

	bool playing = true;
	char y_n; //variable that stores answer to whether or not user wants to play again
	int X_wins = 0; //variable that stores how many times player X has won
	int O_wins = 0; //variable that stores how many times player O has won
	int X_turn = 0;
	int O_turn = 1;
	int turn = X_turn; //start with Player X


	cout << "Player X will go first. Enter a letter (a/b/c) followed by a number (1/2/3) to place your token (e.g. \'a1\')." << endl;


	while (playing) 
	{
		while (!check_win(player_X) && !check_win(player_O) && !check_tie()) 
		{
			print_board();
			char input[3];
			cin >> input;

			
			if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') { //check for valid input
				cout << "Row must be an a, b or c." << endl;
			}
			else if (input[1] != '1' && input[1] != '2' && input[1] != '3') { //check for valid input
				cout << "Column must be a 1, 2, or 3." << endl;
			}
			else {
				int row = input[0] - 'a'; //subtract to get row index 
				int column = input[1] - '1'; //subtract to get column index 
		
				if (board[row][column] == empty) { //place token if spot available
					if (turn == X_turn) {
						board[row][column] = 'X';
						turn = O_turn;
					}
					else {
						board[row][column] = 'O';
						turn = X_turn;
					}
				}
				else {
					cout << "There is already a token there." << endl; 
				}
			}

			if (strlen(input) > 2) { //prompt for input in correct format
				cout << "Next time please enter only one number (1/2/3) following the letter (e.g. \'a1\')." << endl;
			}

		}



		if (check_win(player_X)) {
			X_wins++;
			//print results
			print_board();
			cout << "Player X won this round!" << endl;
			cout << "Player X has " << X_wins << " wins." << endl;
			cout << "Player O has " << O_wins << " wins." << endl;
		}
		else if (check_win(player_O)) {
			O_wins++;
			//print results
			print_board();
			cout << "Player O won this round!" << endl;
			cout << "Player X has " << X_wins << " wins." << endl;
			cout << "Player O has " << O_wins << " wins." << endl;
		}
		else if (check_tie) {
			//print results
			print_board();
			cout << "This round ends in a tie." << endl;
			cout << "Player X has " << X_wins << " wins." << endl;
			cout << "Player O has " << O_wins << " wins." << endl;
		}



		//ask if user wants to continue playing or not
	    while (true)
	    {
	    	cout << "Play again (y/n)? " << endl;
	    	cin >> y_n;

	    	//check if user entered a valid response
	    	if (y_n == 'y' || y_n == 'Y' || y_n == 'n' || y_n == 'N')
	    	{
	        	break;
	      	} 
	    	else {
	        	cout << "Please enter \'y\' or \'Y\' or \'n\' or \'N\'" << endl;
	      	}
	    }
	   
	    //restart or end game based on user response
	    if (y_n == 'y' || y_n == 'Y')
	    {
	    	playing = true;
	    	for (int i = 0; i < 3; i++) { //reset game board
    			for (int j = 0; j < 3; j++) {
    				board[i][j] = empty;
    			}
   			}
	      	turn = X_turn; //make player X turn again
	    }
	    else if (y_n == 'n' || y_n == 'N')
	    {
	      	playing = false;
	      	cout << "Okay. Thanks for playing!";
	    }

	}

	return 0;
} // end of main



//function to print the game board
void print_board()
{
	cout << " \t1\t2\t3" << endl; //print column labels
	cout << 'a' << '\t' << board[0][0] << '\t' << board[0][1] << '\t' << board[0][2] << endl;
	cout << 'b' << '\t' << board[1][0] << '\t' << board[1][1] << '\t' << board[1][2] << endl;
	cout << 'c' << '\t' << board[2][0] << '\t' << board[2][1] << '\t' << board[2][2] << endl;
} //end of print_board



//function to check if player_X or player_O has won
bool check_win(char player) 
{
	if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
		return true;
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		return true;
	}
	if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
		return true;
	}
	if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
		return true;
	}
	if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
		return true;
	}
	if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
		return true;
	}
	if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
		return true;
	}
	if (board[2][0] == player && board[1][1] == player && board[2][0] == player) {
		return true;
	}
	return false;
} //end of check_win


//function to check if the round ended in a tie
bool check_tie() 
{
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (board[r][c] == empty) {
				return false; //there are still empty spots on the grid left to play
			}
		}
	}
	return true; //all spots on the grid have been filled
} //end of check_tie

