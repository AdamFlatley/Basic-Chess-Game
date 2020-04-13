#include "Queen.h"

Queen::Queen(const char Colour) : Piece(Colour) {}
Queen::~Queen() {}
char Queen::getPiece() { return 'Q'; }
int Queen::allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol) {
		int RowDiff = StartRow - DestRow;
		int ColDiff = StartCol - DestCol;
		if ((RowDiff == 0 && ColDiff != 0) || (RowDiff != 0 && ColDiff == 0) // if horizontal/vertical
			|| (RowDiff == ColDiff != 0) || (RowDiff == -ColDiff != 0)){  // or if diagonal
			return 1;
		}
		else{
			return 0;
		}
	}
