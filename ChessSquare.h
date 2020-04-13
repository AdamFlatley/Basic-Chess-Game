#pragma once
#include "Piece.h"


class ChessSquare{
	int SRow;				// used to find and set the colour of the square for output.
	int SColumn;
	char SColour;			// square colour
	
public:
	Piece *thing;
	ChessSquare();
	ChessSquare(const int Row, const int Column, Piece *piece);

	//square destructor
	~ChessSquare();
	//begin functions
	char getsquarecolour(); // gets squares colour
	char getpiececolour(); // gets the colour of piece pointed to by square
	char getpiece();	// gets the piece pointed to by the square
	void SetStartSq();	// if is square being moved from by a piece this function is used to change piece pointer
	void SetDestSq(Piece* incoming);	// if is moved to by a piece this is used to change piece pointer
};
