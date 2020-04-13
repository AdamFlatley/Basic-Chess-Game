#include "Castle.h"

Castle::Castle(const char Colour) : Piece(Colour) {}
Castle::~Castle() {}
char Castle::getPiece() { return 'C'; }
int Castle::allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol) {
		int RowDiff = StartRow - DestRow;
		int ColDiff = StartCol - DestCol;
		if ((RowDiff == 0 && ColDiff != 0) || (RowDiff != 0 && ColDiff == 0)){		//move horizontally/vertically
			return 1;
		}
		else{
			return 0;
		}
	}