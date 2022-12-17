#include "Board.h"
void Board::Board_Side(int size) 
{
	side_len = size;
}

void Board::setMines(int mine) {
	mines = mine;
}

int Board::getSide() {
	return side_len;
}

void Board::printBoard(char myBoard[][MAXSIDE]) {
	cout << "     ";
	for (int i = 0; i < getSide(); i++)
		printf("%d ", i);
	cout << endl << endl;
	for (int i = 0; i < getSide(); i++) {
		printf("%d   ", i);
		for (int j = 0; j < getSide(); j++)
			printf("%c ", myBoard[i][j]);
		cout << endl;
	}
	return;
}

int Board::getMines() {
	return mines;
}