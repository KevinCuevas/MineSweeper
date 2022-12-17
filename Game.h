#include "Board.h"
#pragma once
class Game :public Board
{
public:
	void chooseDifficulty();
	void assignMoves();
	bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard [][MAXSIDE], int mines[][2], int, int, int*);
	bool isValidMove(int row, int col);//checks to see if the user move is valid in the borad space and not somewhere else
	bool isMine(int row, int col, char board[][MAXSIDE]);//check if the cell has a mine
	void makeMove(int* x, int* y);
	int countMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]);//counts the number of mines
	void placeMines(int mines[][2], char realBoard[][MAXSIDE]);
	void initialise(char realBoard[][MAXSIDE], char[][MAXSIDE]);
	void playMinesweeper();
	void replaceMine(int row, int col, char board[][MAXSIDE]);
};

