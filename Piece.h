//first class declarations made, don't need to include other header files.
#pragma once
class Piece{
public:
	Piece();
	Piece(const char Colour);
	~Piece();
	char getColour(); // get colour of the piece
	virtual char getPiece() = 0;	// get the type of piece, different for each piece
	//function to check if piece is allowed to move to destination square.
	virtual int allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol) = 0;
private:
	char PieceColour; // stores colour of the piece
};
