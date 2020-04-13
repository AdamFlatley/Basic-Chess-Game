#pragma once
#include "Piece.h"


class Castle : public Piece{
public:
	Castle(const char Colour);
	~Castle();
	char getPiece();
	int allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol);
};