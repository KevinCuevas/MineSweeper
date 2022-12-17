#include "Game.h"
void Game::chooseDifficulty() {
	int level;
	cout << "Choose which level 1)Beginner, 2) Intermediate, 3)Advance" << endl;
	cin >> level;
	if (level == 1) {
		Board_Side(9);
		setMines(10);
	}
	else if (level == 2) {
		Board_Side(16);
		setMines(40);
	}
	else if (level == 3) {
		Board_Side(24);
		setMines(99);
	}
	return;
}

void Game::assignMoves() {

}

bool Game::isValidMove(int row, int col) {
	return (row >= 0) && (row < getSide()) && (col >= 0) && (col < getSide());
}

bool Game::isMine(int row, int col, char board[][MAXSIDE]) {
	if (board[row][col] == '*')
		return true;
	else return false;
}


void Game::makeMove(int *x, int *y) {
	cout << "Make your move, select a row number then enter then same with col : ";
	scanf_s("%d %d", x, y);
	return;
}

int Game::countMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]) {
	int count = 0;

	//north
	if (isValidMove(row - 1, col) == true)
	{
		if (isMine(row - 1, col, realBoard) == true)
			count++;
	}
	if (isValidMove(row + 1, col) == true)
	{
		if (isMine(row + 1, col, realBoard) == true)
			count++;
	}
	if (isValidMove(row, col + 1) == true)
	{
		if (isMine(row, col + 1, realBoard) == true)
			count++;
	}
	if (isValidMove(row, col - 1) == true)
	{
		if (isMine(row, col - 1, realBoard) == true)
			count++;
	}
	if (isValidMove(row - 1, col + 1) == true)
	{
		if (isMine(row - 1, col + 1, realBoard) == true)
			count++;
	}
	if (isValidMove(row - 1, col - 1) == true)
	{
		if (isMine(row - 1, col - 1, realBoard) == true)
			count++;
	}
	if (isValidMove(row + 1, col + 1) == true)
	{
		if (isMine(row + 1, col + 1, realBoard) == true)
			count++;
	}
	if (isValidMove(row + 1, col - 1) == true)
	{
		if (isMine(row + 1, col - 1, realBoard) == true)
			count++;
	}
	return count;
}
bool Game::playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE], int mines[][2], int row, int col, int* movesLeft) {
	if (myBoard[row][col] != '-') return false;

	if (realBoard[row][col] == '*')
	{
		myBoard[row][col] = '*';
		for (int i = 0; i < getMines(); i++){
			myBoard[mines[i][0]][mines[i][1]] = '*';
			printBoard(myBoard);
			cout << "\nYou lost!\n";
			return true;
		}
	}
	else {
		int count = countMines(row, col, mines, realBoard);
		(*movesLeft)--;
		myBoard[row][col] = count + '0';
		if (!count) {
			if (isValidMove(row - 1, col) == true)
			{
				if (isMine(row - 1, col, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row - 1, col, movesLeft);
			}
			if (isValidMove(row + 1, col) == true)
			{
				if (isMine(row + 1, col, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row + 1, col, movesLeft);
			}
			if (isValidMove(row, col + 1) == true)
			{
				if (isMine(row, col + 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col + 1, movesLeft);
			}
			if (isValidMove(row, col - 1) == true)
			{
				if (isMine(row, col - 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col - 1, movesLeft);
			}
			if (isValidMove(row - 1, col + 1) == true)
			{
				if (isMine(row - 1, col + 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row - 1, col + 1, movesLeft);
			}
			if (isValidMove(row - 1, col - 1) == true)
			{
				if (isMine(row - 1, col - 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row - 1, col - 1, movesLeft);
			}
			if (isValidMove(row + 1, col + 1) == true)
			{
				if (isMine(row + 1, col + 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row + 1, col + 1, movesLeft);
			}
			if (isValidMove(row + 1, col - 1) == true)
			{
				if (isMine(row + 1, col - 1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row + 1, col - 1, movesLeft);
			}
		}
		return false;
	}
}
void Game::placeMines(int mines[][2], char realBoard[][MAXSIDE]) {
	bool mark[MAXSIDE * MAXSIDE];
	memset(mark, false, sizeof(mark));

	for (int i = 0; i < getMines();) {
		int random = rand() % (getSide() * getSide());
		int x = random / getSide();
		int y = random % getSide();
		if (mark[random] == false)
		{
			mines[i][0] = x;
			mines[i][1] = y;
			realBoard[mines[i][0]][mines[i][1]] = '*';
			mark[random] = true;
			i++;
		}
	}
	return;
}
void Game::initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]){
	srand(time(NULL));

	for (int i = 0; i < getSide(); i++) {
		for (int j = 0; j < getSide(); j++) {
			myBoard[i][j] = realBoard[i][j] = '-';
		}
	}
	return;
}
void Game::replaceMine(int row, int col, char board[][MAXSIDE])
{
	for (int i = 0; i < getSide(); i++) {
		for (int j = 0; j < getSide(); j++) {
			if (board[i][j] != '*') {
				board[i][j] = '*';
				board[row][col] = '-';
				return;
			}
		}
	}
	return;
}
void Game::playMinesweeper() {
	bool gameOver = false;
	char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE];
	int movesLeft = getSide() * getSide() - getMines(), x, y;
	int mines[MAXMINES][2];
	initialise(realBoard, myBoard);
	placeMines(mines, realBoard);
	int currentMoveIndex = 0;
	while (gameOver == false)
	{
		cout << "Current Status of board : " << endl;
		printBoard(myBoard);
		makeMove(&x, &y);
		if (currentMoveIndex == 0) {
			if (isMine(x, y, realBoard) == true)
				replaceMine(x, y, realBoard);
		}
		currentMoveIndex++;
		gameOver = playMinesweeperUtil(myBoard, realBoard, mines, x, y, &movesLeft);
		if ((gameOver == false) && (movesLeft == 0)) 
		{
			cout << "You Won!" << endl;
			gameOver = true;
		}
	}
	return;
}