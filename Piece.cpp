#include "Piece.h"


Piece::Piece() { PieceColour = 'E'; }//if default constructor called just sets colour to empty

Piece::Piece(const char Colour) : PieceColour(Colour) {} //paramaterised constructor only with colour
	
Piece::~Piece() {} // Deconstructor

char Piece::getColour() {return PieceColour;} //function to return colour of a piece.

