#include "King.h"
King::King(const char Colour) : Piece(Colour) {}
King::~King() {}
char King::getPiece() { return 'K'; }
int King::allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol) {
		int RowDiff = StartRow - DestRow;
		int ColDiff = StartCol - DestCol;
		if ((RowDiff <= 1 && RowDiff >= -1) && (ColDiff <= 1 && ColDiff >= -1)){ // can move one square any direction
			return 1;
		}
		else { return 0; 
		}
}