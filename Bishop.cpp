#include "Bishop.h"

Bishop::Bishop(const char Colour) : Piece(Colour) {}
Bishop::~Bishop() { }
char Bishop:: getPiece() { return 'B'; }
int  Bishop::allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol) {
		int RowDiff = StartRow - DestRow;
		int ColDiff = StartCol - DestCol;
		if ((RowDiff == ColDiff != 0) || (RowDiff == -ColDiff != 0)){ // must move diagonally
			return 1;
		}
		else {
			return 0;
		}
	}
