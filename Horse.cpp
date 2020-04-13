#include "Horse.h"

Horse::Horse(const char Colour) : Piece(Colour) {}
Horse::~Horse() {}
char Horse::getPiece() { return 'H'; }
int Horse::allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol) {
		int RowDiff = StartRow - DestRow;
		int ColDiff = StartCol - DestCol;
		if ((RowDiff == 2 && ColDiff == 1) || (RowDiff == 2 && ColDiff == -1) || (RowDiff == -2 && ColDiff == 1)
			|| (RowDiff == -2 && ColDiff == -1) || (RowDiff == 1 && ColDiff == 2) || (RowDiff == 1 && ColDiff == -2)
			|| (RowDiff == -1 && ColDiff == 2) || (RowDiff == -1 && ColDiff == -2)){
			return 1;
		}
		else {
			return 0;
		}
}