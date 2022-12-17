#include <iostream>
using namespace std;
#pragma once
#define MAXSIDE 25
#define MAXMINES 99
#define MOVESIZE 526 // (25 * 25 - 99)
class Board
{
private:
	int side_len; // side length of the board 
	int mines; //number of mines will be put into the board 
public:
	void Board_Side(int side);
	void setMines(int mine);
	void myBoard();//this board will change as the user will be using this to move 
	void realBoard();//this board will have the mines
	int getSide();
	void printBoard(char myBoard[][MAXSIDE]);
	int getMines();
};

