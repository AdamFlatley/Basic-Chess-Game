#pragma once

#include "Piece.h"

class Queen : public Piece{
public:
	Queen(const char Colour);
	~Queen();
	char getPiece();
	int allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol);
};
