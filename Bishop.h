#pragma once
#include "Piece.h"

class Bishop : public Piece{
public:
	Bishop(const char Colour);
	~Bishop();
	char getPiece();
	int allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol);
};
