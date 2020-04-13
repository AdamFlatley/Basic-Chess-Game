
#pragma once
#include "ChessSquare.h"



class Chessboard {

public:
	ChessSquare* gameboard[8][8]; // board is a pointer to 8x8 array of squares.
	Chessboard(); //default constructor only
	~Chessboard(); // destructor to delete all the contents of the board.

	void printboard();// output the board
	int isempty(int row, int col);		// tests if a given square is empty returns positive if it is.
	//checks to see if a piece is blocking the path of moving piece
	bool pieceblocking(const int startrow, const int startcol, const int destrow, const int destcol);
	// one of the most important functions in the program
	//takes the user input, tests whether the move is allowed or not then performs the output if it is valid
	//if not will output a suitable error message.

	bool movepieces(const int startrow, const int startcol, const int destrow, const int destcol);

	//function that checks if current user is in check and informs them if they are
	bool incheck(const int kingrow, const int kingcol, const char turncolour);
};