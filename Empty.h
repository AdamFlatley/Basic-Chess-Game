#pragma once

#include "Piece.h"

class Empty : public Piece{
public:
	Empty();
	~Empty();
	char getPiece();
	int allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol);
};
