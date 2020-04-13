//Program that runs the board game chess
//created by Adam Flatley
//intended for use by 2 players (no computer)
//12/05/2019
//the program depends on header and code files for each pieces, chesssquares and the chessboard itself

#include <iostream>
#include <string>
#include "Chessboard.h"

//function defined to take input of movement
std::string takeinput(){
	std::string usersinput;
	std::cout << "Please select a square (col,row): \n";
	getline(std::cin, usersinput);
	if (usersinput == "exit"){					// user 
		std::cout << "Thank you for using the program. \n";
		system("PAUSE");
		exit(1);
	}
	if (usersinput == "N" || usersinput == "n"){ // user deselecting their piece
		return "n";
	}
	if (usersinput.length() == 3){
		if (isdigit(usersinput[0]) && (usersinput[0] != ("0" && "9"))){
			if (usersinput[1] == ','){
				if (isdigit(usersinput[2]) && (usersinput[2] != ("0" && "9"))){
					return usersinput;
				}
			}
		}
	}
	else{
			return "invalid";
	}
	return "invalid";
}


int main(){
	std::string startgame;
	std::string input;
	int firstnumber;
	int secondnumber;
	char colourturn = 'W'; //whites go first
	bool endofgame = false;

	std::cout << "Welcome to Chess! \n";
	std::cout << "This Code is Designed for use by two players \n";
	std::cout << "In order to play the game you will need to input two numbers twice per turn. \n";
	std::cout << "For your first input type a 2 digits in the form of COLUMN,ROW to select the piece you wish to move.\n";
	std::cout << "After you have selected your piece type in the same format to choose where you wish to move to.\n";
	std::cout << "If you wish to deselelect the piece you chose type (N).\n";
	std::cout << "The game will let you know if you have performed an illegal move and let you retake your go. \n";
	std::cout << "The win condition for the game is that a king actually has to be captured. The game will let you know if you are in check.\n";
	std::cout << "However, the game will not stop you from moving into check so be careful!.\n";
	std::cout << "And finally if you wish to exit, type (exit) \n";
	std::cout << "If you are ready please type (Y) \n";
	while(startgame != "Y" && startgame != "y"){ // simple intro screen for the user  to read the rules and controls
		getline(std::cin, startgame);
		if (startgame == "exit"){
			exit(1);
		}
	}
	Chessboard board; // board is initialised
	while (!endofgame){ // each loop is a turn
		board.printboard(); // whilst not end of game will print the board at the start
		int kingrow; // used to find the kings and tell user whether they are in check or not as a warning.
		int kingcol;
		int numberofkings = 0;
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				if ((board.gameboard[i][j]->getpiece() == 'K') && (board.gameboard[i][j]->getpiececolour() == colourturn)){
					kingrow = i;
					kingcol = j;
				}/// Need to check if a king is missing
				if (board.gameboard[i][j]->getpiece() == 'K'){
					numberofkings++;

					
				}
			}
		}
		if (numberofkings < 2){//if less than two kings are found on the board the board finds the colour f the remaining king
								//outputs the winner and ends program
			for (int i = 0; i < 8; i++){
				for (int j = 0; j < 8; j++){
					if ((board.gameboard[i][j]->getpiece() == 'K') && (board.gameboard[i][j]->getpiececolour() == 'W')){
						std::cout << " WHITE WINS!.\n"; system("PAUSE"); return 0;
					}
					if ((board.gameboard[i][j]->getpiece() == 'K') && (board.gameboard[i][j]->getpiececolour() == 'B')){
						std::cout << "BLACK WINS!.\n"; system("PAUSE"); return 0;
					}
				}
			}
		
		}
	
		if (colourturn == 'W'){ std::cout << "It is Whites Turn.\n"; } // checks whose turn it is.
		if (colourturn == 'B'){ std::cout << "It is Black's Turn.\n"; }
		//checks if in check
		board.incheck(kingrow, kingcol, colourturn);
		//takes input
		input = takeinput();
		if (input == "invalid"){ std::cout << "your input was invalid, please try again.\n"; system("PAUSE"); }// if input is invalid
		else{
			if (input == "n"){ std::cout << "you haven't selected a piece yet.\n"; system("PAUSE"); }
			else{
				firstnumber = int (input[0]-48);	//values of char numbers start at 48, so -48 as crude solution
				secondnumber = int ( input[2]-48);
				
				if (board.gameboard[secondnumber - 1][firstnumber - 1]->getpiececolour() == colourturn){
					std::cout << "Piece selected.\n"; // tells user they have selected a piece
					input = takeinput();
					if (input == "invalid"){ std::cout << "your input was invalid, please try again.\n"; system("PAUSE"); }// if input is invalid
					else{
						if (input == "n"){ std::cout << "you deselected your piece.\n"; system("PAUSE"); }
						else{
							if (board.movepieces(secondnumber-1, firstnumber -1, input[2] - 49, input[0] - 49)){
								if (colourturn == 'W'){ // changes turn if successful move
									colourturn = 'B';
								}
								else{
									colourturn = 'W';
								}
							}
							
						}
					}

					
				}
				else{
					std::cout << "That isnt your piece!\n"; system("PAUSE");
				}

			}
		}
	} // returns to start of program
	return 0;
}
