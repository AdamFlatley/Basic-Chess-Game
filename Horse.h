#pragma once
#include "Piece.h"

class Horse : public Piece{
public:
	Horse(const char Colour);
	~Horse();
	char getPiece();
	int allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol);
};
