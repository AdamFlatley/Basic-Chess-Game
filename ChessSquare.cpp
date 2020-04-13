#include "ChessSquare.h"
#include "Empty.h"

ChessSquare::ChessSquare() { SRow = 0; SColumn = 0; SColour = 'E'; SColour = 'E'; thing = new Empty; } // default to create an empty square (isn't used in program though)
ChessSquare::ChessSquare(const int Row, const int Column, Piece *piece) {
		SRow = Row; SColumn = Column; thing = piece; // sets values of sqyare
		if ((Row + Column) % 2 == 0) { SColour = 'W'; } // set square colours depending on location
		else { SColour = 'B'; }
	}
	//square destructor
ChessSquare::~ChessSquare(){ delete thing; }
	//begin functions
char ChessSquare::getsquarecolour() { return SColour; }

char ChessSquare::getpiececolour() {
		return thing->getColour();
	}
char ChessSquare::getpiece(){
		return thing->getPiece();
	}

void ChessSquare::SetStartSq(){
		thing = new Empty; // when moving a piece, will set the square that is moved from to an empty square.
	}
void ChessSquare::SetDestSq(Piece* incoming){
		thing = incoming;  // sets the destination square to the piece being moved.
	}