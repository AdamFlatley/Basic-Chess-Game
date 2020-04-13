
#include "Pawn.h"

Pawn::Pawn(const char Colour) : Piece(Colour) {}
Pawn::~Pawn() { }
char Pawn::getPiece() { return 'P'; }

int Pawn::allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol) {
		int RowDiff = StartRow - DestRow;
		int ColDiff = StartCol - DestCol;
		if (ColDiff == 0){
			if (getColour() == 'W'){
				if ((StartRow - DestRow == 1) || (StartRow == 6 && StartRow - DestRow == 2)){ return 1; } // move 1 forward always, 2 forward allowed from start
				else{ return 0; } // if starting squares allows movement of 2
			}
			if (getColour() == 'B'){
				if (StartRow - DestRow == -1 || (StartRow == 1 && StartRow - DestRow == -2)){ return 1; }
				else{ return 0; }
			}
			else{ return 0; }
		}
		if (ColDiff <= 1 && ColDiff >= -1){
			if (getColour() == 'W'){
				if ((StartRow - DestRow == 1)) { return 1; } // move 1 forward always, 2 forward allowed from start
				else{ return 0; }
			}
			if (getColour() == 'B'){
				if ((StartRow - DestRow == -1)){ return 1; }
				else{ return 0; }
			}
		}

		return 0;
	}