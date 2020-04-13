//potentially longest of all files
//includes lots of codes for moving pieces, checking if a move is valid and checking if a king is in check
#include "Chessboard.h"
#include "Piece.h"
#include "Bishop.h"
#include "Castle.h"
#include "King.h"
#include "Horse.h"
#include "Pawn.h"
#include "Queen.h"
#include "Empty.h"
#include <iostream>

Chessboard::Chessboard() {
		for (int Row = 2; Row < 6; ++Row) {  // constructor to initialise the board and set them all
			for (int Col = 0; Col < 8; ++Col) {
				gameboard[Row][Col] = new ChessSquare(Row, Col, new Empty); //sets middle 4 rows to empties.
			}
		}
		//Create White pieces
		for (int column = 0; column < 8; ++column){
			gameboard[6][column] = new ChessSquare(6, column, new Pawn('W')); //  Creates white pawns
		}
		gameboard[7][0] = new ChessSquare(7, 0, new Castle('W')); // sets other white pieces
		gameboard[7][1] = new ChessSquare(7, 1, new Horse('W'));
		gameboard[7][2] = new ChessSquare(7, 2, new Bishop('W'));
		gameboard[7][3] = new ChessSquare(7, 3, new Queen('W'));
		gameboard[7][4] = new ChessSquare(7, 4, new King('W'));
		gameboard[7][5] = new ChessSquare(7, 5, new Bishop('W'));
		gameboard[7][6] = new ChessSquare(7, 6, new Horse('W'));
		gameboard[7][7] = new ChessSquare(7, 7, new Castle('W'));
		//Create Black pieces
		for (int column = 0; column < 8; ++column){
			gameboard[1][column] = new ChessSquare(1, column, new Pawn('B')); // Black pawns
		}
		gameboard[0][0] = new ChessSquare(0, 0, new Castle('B')); // other black pieces
		gameboard[0][1] = new ChessSquare(0, 1, new Horse('B'));
		gameboard[0][2] = new ChessSquare(0, 2, new Bishop('B'));
		gameboard[0][3] = new ChessSquare(0, 3, new Queen('B'));
		gameboard[0][4] = new ChessSquare(0, 4, new King('B'));
		gameboard[0][5] = new ChessSquare(0, 5, new Bishop('B'));
		gameboard[0][6] = new ChessSquare(0, 6, new Horse('B'));
		gameboard[0][7] = new ChessSquare(0, 7, new Castle('B'));

	}

Chessboard::~Chessboard(){
	for (int Row = 0; Row < 8; ++Row) {  // destructor to delete all the contents of the board.
		for (int Col = 0; Col < 8; ++Col) {
			delete gameboard[Row][Col];
			
		}
	}
}

	//function for outputting the board
void Chessboard::printboard() {
		system("CLS"); // clear the screen
		std::cout << "To exit game, type (exit)\n"; // output method for exiting the game early if needed.
		std::cout << "  ";
		for (int i = 0; i < 8; i++){
			std::cout << "+====" << i + 1 << "====+"; // create top edge of board
		}
		std::cout << "\n";
		//begins outputting squares, does 8 rows of squares, with depth of 5 lines by 8 columns
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 5; j++){
				for (int k = 0; k < 8; k++){
					if (j == 0 || j == 3){ //for 1st and 4th line output will only depend on colour of square so only checks this

						if (gameboard[i][k]->getsquarecolour() == 'W'){
							if (k == 0){
								std::cout << "  ";
							}
							std::cout << "|#########|";
							if (k == 7){ std::cout << "\n"; }
							//prints colours of squares and board
						}
						if (gameboard[i][k]->getsquarecolour() == 'B'){
							if (k == 0){
								std::cout << "  ";
							}
							std::cout << "|         |";
							if (k == 7){ std::cout << "\n"; }

						}

					}


				}

				if (j == 1){ // for second line only checks colour of piece occupying square + colour of square itself
					// this line also contains reference number for co-ordinates if first column of the row.
					for (int k = 0; k < 8; k++){
						if (gameboard[i][k]->getpiececolour() == 'W'){
							if (gameboard[i][k]->getsquarecolour() == 'W'){
								if (k == 0){
									std::cout << i + 1 << " ";
								}
								std::cout << "|# WHITE #|";
								if (k == 7){ std::cout << "\n"; }
								//prints colours of squares and board
							}
							if (gameboard[i][k]->getsquarecolour() == 'B'){
								if (k == 0){
									std::cout << i + 1 << " ";
								}
								std::cout << "|  WHITE  |";
								if (k == 7){ std::cout << "\n"; }

							}

						}
						if (gameboard[i][k]->getpiececolour() == 'B'){
							if (gameboard[i][k]->getsquarecolour() == 'W'){
								if (k == 0){
									std::cout << i + 1 << " ";
								}
								std::cout << "|# BLACK #|";
								if (k == 7){ std::cout << "\n"; }
								//prints colours of squares and board
							}
							if (gameboard[i][k]->getsquarecolour() == 'B'){
								if (k == 0){
									std::cout << i + 1 << " ";
								}
								std::cout << "|  BLACK  |";
								if (k == 7){ std::cout << "\n"; }

							}

						}
						if (gameboard[i][k]->getpiececolour() == 'E'){
							if (gameboard[i][k]->getsquarecolour() == 'W'){
								if (k == 0){
									std::cout << i + 1 << " ";
								}
								std::cout << "|#########|";
								if (k == 7){ std::cout << "\n"; }
								//prints colours of squares and board
							}
							if (gameboard[i][k]->getsquarecolour() == 'B'){
								if (k == 0){
									std::cout << i + 1 << " ";
								}
								std::cout << "|         |";
								if (k == 7){ std::cout << "\n"; }
							}
						}
					}
				}

				//// on 3rd output line depends on actual piece present and colour of square so checks accordingly.
				// there are many different possible outputs for this as seen.
				//checks every single one since moves onto the next square to ensure a definite output.
				//if the output is in the 8th column it will start a new line for the next row.
				if (j == 2){
					for (int k = 0; k < 8; k++){
						if (gameboard[i][k]->getsquarecolour() == 'B'){
							if (gameboard[i][k]->getpiece() == 'P'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|  PAWN   |";
								if (k == 7){ std::cout << "\n"; }
								//prints colours of squares and board
							}
							if (gameboard[i][k]->getpiece() == 'C'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|  CASTLE |";
								if (k == 7){ std::cout << "\n"; }

							}
							if (gameboard[i][k]->getpiece() == 'H'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|  HORSE  |";
								if (k == 7){ std::cout << "\n"; }

							}
							if (gameboard[i][k]->getpiece() == 'B'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|  BISHOP |";
								if (k == 7){ std::cout << "\n"; }

							}
							if (gameboard[i][k]->getpiece() == 'Q'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|  QUEEN  |";
								if (k == 7){ std::cout << "\n"; }

							}
							if (gameboard[i][k]->getpiece() == 'K'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|  KING   |";
								if (k == 7){ std::cout << "\n"; }

							}
							if (gameboard[i][k]->getpiece() == 'E'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|         |";
								if (k == 7){ std::cout << "\n"; }

							}
						}
						if (gameboard[i][k]->getsquarecolour() == 'W'){
							if (gameboard[i][k]->getpiece() == 'P'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|# PAWN  #|";
								if (k == 7){ std::cout << "\n"; }
							}
							if (gameboard[i][k]->getpiece() == 'C'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|# CASTLE#|";
								if (k == 7){ std::cout << "\n"; }

							}
							if (gameboard[i][k]->getpiece() == 'H'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|# HORSE #|";
								if (k == 7){ std::cout << "\n"; }

							}
							if (gameboard[i][k]->getpiece() == 'B'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|# BISHOP#|";
								if (k == 7){ std::cout << "\n"; }

							}
							if (gameboard[i][k]->getpiece() == 'Q'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|# QUEEN #|";
								if (k == 7){ std::cout << "\n"; }

							}
							if (gameboard[i][k]->getpiece() == 'K'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|# KING  #|";
								if (k == 7){ std::cout << "\n"; }

							}
							if (gameboard[i][k]->getpiece() == 'E'){
								if (k == 0){
									std::cout << "  ";
								}
								std::cout << "|#########|";
								if (k == 7){ std::cout << "\n"; }
							}
						}
					}
				}
				if (j == 4){ // for 5th line will create a border for bottom of squares.
					for (int k = 0; k < 8; k++){
						if (k == 0){
							std::cout << "  ";
						}
						std::cout << "+=========+";
					}std::cout << "\n";

				}
			}
		}
	}








int Chessboard::isempty(int row, int col){			// tests if a given square is empty returns positive if it is.
		if (gameboard[row][col]->getpiece() == 'E'){
			return 1;
		}

		else{ return 0; }
	}


	//checks to see if a piece is blocking the path of moving piece
	//determines how the piece is moving then checks all the squares in between the start and destination squares accordingly.
bool Chessboard::pieceblocking(const int startrow, const int startcol, const int destrow, const int destcol){
		int RowDiff = startrow - destrow;
		int ColDiff = startcol - destcol;
		if (ColDiff >= -1 && ColDiff <= 1 && RowDiff >= -1 && RowDiff <= 1){ return false; } // if only moving one square passes instantly since cannot be blocked.
		if (RowDiff == 0 && ColDiff > 1){ // is moving left 
			for (int i = 0; (startcol - i - 1) > destcol; i++){
				if (isempty(startrow, startcol - i - 1) == 0){ return true; }
			}
		}
		if (RowDiff == 0 && ColDiff < -1){// is moving right
			for (int i = 0; (startcol + i + 1) < destcol; i++){
				if (isempty(startrow, startcol + i + 1) == 0){ return true; }
			}
		}
		if (ColDiff == 0 && RowDiff > 1){// is moving upwards
			for (int i = 0; (startrow - i - 1) > destrow; i++){
				if (isempty(startrow - i - 1, startcol) == 0){ return true; }
			}
		}
		if (ColDiff == 0 && RowDiff < -1){// is moving downwards
			for (int i = 0; (startrow + i + 1) < destrow; i++){
				if (isempty(startrow + i + 1, startcol) == 0){ return true; }
			}
		}
		if (ColDiff == RowDiff && RowDiff > 1){// move upleft diagonally
			for (int i = 0; (startrow - i - 1) > destrow; i++){
				if (isempty(startrow - i - 1, startcol - i - 1) == 0){ return true; }
			}
		}
		if (ColDiff == RowDiff && RowDiff < -1){// down right diagonally
			for (int i = 0; (startrow + i + 1) < destrow; i++){
				if (isempty(startrow + i + 1, startcol + i + 1) == 0){ return true; }
			}
		}
		if (ColDiff == -RowDiff && RowDiff > 1){// up right diagonally
			for (int i = 0; (startrow - i - 1) > destrow; i++){
				if (isempty(startrow - i - 1, startcol + i + 1) == 0){ return true; }
			}
		}
		if (ColDiff == -RowDiff && RowDiff < -1){// down left diagonally
			for (int i = 0; (startrow + i + 1) < destrow; i++){
				if (isempty(startrow + i + 1, startcol - i - 1) == 0){ return true; }
			}
		}

		return false; // if isnt blocked by specified path returns false.
	}




bool Chessboard::movepieces(const int startrow, const int startcol, const int destrow, const int destcol){
		if (gameboard[startrow][startcol]->thing->allowedmove(startrow, startcol, destrow, destcol)){// checks is a valid move in terms of pieces available moves
			if ((gameboard[startrow][startcol]->thing->getColour()) != (gameboard[destrow][destcol]->thing->getColour())){ // checks destination doesn't have the same colour piece present
				if ((gameboard[startrow][startcol]->getpiece() != 'P')){
					//checks if horse, if horse skips blocking check
					if ((gameboard[startrow][startcol]->getpiece() != 'H')){
						//if piece is not blocked will make the move
						if (!pieceblocking(startrow, startcol, destrow, destcol)){
							gameboard[destrow][destcol]->SetDestSq(gameboard[startrow][startcol]->thing);
							gameboard[startrow][startcol]->SetStartSq();
							return true;
						}
						else{
							std::cout << "you cannot do that a piece is in the way. \n";
							system("PAUSE");
							return false;

						}
					}
					else{
						//doesnt check for blocking pieces for horses
						gameboard[destrow][destcol]->SetDestSq(gameboard[startrow][startcol]->thing);
						gameboard[startrow][startcol]->SetStartSq();
						return true;
					}
				}
				else{ // if piece is a pawn obeys different rules for capturing so as follows
					if (startcol - destcol != 0){
						if ((gameboard[destrow][destcol]->thing->getColour()) != 'E'){ // if diagonal is empty and not same coloured allowed move.
							gameboard[destrow][destcol]->SetDestSq(gameboard[startrow][startcol]->thing);
							gameboard[startrow][startcol]->SetStartSq();
							return true;
						}
						else{
							std::cout << "pawn cannot move diagonally unless capturing units.\n"; system("PAUSE"); return false;
						}
					}
					if (startcol - destcol == 0){
						if ((gameboard[destrow][destcol]->thing->getColour()) == 'E'){ // if in front is not empty and not same coloured allowed move.
							gameboard[destrow][destcol]->SetDestSq(gameboard[startrow][startcol]->thing);
							gameboard[startrow][startcol]->SetStartSq();
							return true;
						}
						else{
							std::cout << "pawn cannot capture units by moving forwards.\n"; system("PAUSE"); return false;
						}
					}
				}
			}
			else{ std::cout << "You can't move onto your own piece \n"; system("PAUSE"); return false; }
		}


		else{
			std::cout << "that move isn't allowed. \n";
			system("PAUSE");
			return false;
		}
		return false;
	}


bool Chessboard::incheck(const int kingrow, const int kingcol, const char turncolour){
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){ // iterate through all game board squares
				if ((gameboard[i][j]->getpiececolour() != turncolour) && (gameboard[i][j]->getpiececolour() != 'E')){ // if piece found is of opposite colour to turn
					if (gameboard[i][j]->thing->allowedmove(i, j, kingrow, kingcol)){
						if (gameboard[i][j]->getpiece() == 'H'){ // horse doesnt obey blocking so do first
							std::cout << "Your king is in check.\n"; return true;
						}
						if (gameboard[i][j]->getpiece() == 'P'){ //if its a pawn since only takes diagonally
							if (j - kingcol != 0){
								std::cout << "Your king is in check.\n"; return true;
							}
							else{ return false; }
						}
						if (!pieceblocking(i, j, kingrow, kingcol)){  // rest of pieces need block checking
							std::cout << "Your king is in check.\n"; return true;
						}
					}
				}

			}
		} return false;
	}
