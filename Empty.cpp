#include "Empty.h"

Empty::Empty() : Piece('E'){}
Empty::~Empty() {}
char Empty::getPiece() { return 'E'; }
int Empty::allowedmove(const int StartRow, const int StartCol, const int DestRow, const int DestCol) { return 0; } // Can't move from this
