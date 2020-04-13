#pragma once
#include "Piece.h"


class Pawn : public Piece{
public:
	Pawn(const char Colour);
	~Pawn();
	char getPiece();
	int allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol);
};