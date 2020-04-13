#pragma once
#include "Piece.h"


class King : public Piece{
public:
	King(const char Colour);
	~King();
	char getPiece();
	int allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol);
};