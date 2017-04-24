#include <iostream>

//Global variables
int gameBoardSize = 3; //for an nxn board
char gameBoard [gameBoardSize][gameBoardSize]; //TicTacToe board

//User-defined functions
void updatePosition(int x, int y, char player);
void printBoard();
void initGameBoard();
char winner();
char checkRow(int r);
char checkCol(int c);
char checkDiag(int d);


int main() {
	while (winner() != ' ') {
	
	}


	return 0;
}

void printBoard() {
	for (int i=0; i<gameBoardSize; i++) {
		for (int j=0; j<gameBoardSize-1; j++) {
			std::cout << " " << gameBoard[i][j] << " |";
		}
	}
}

char winner() {
	for (int i=0; i<gameBoardSize; i++) {
		if (checkRow(i) != ' ') {
			return checkRow(i);
		}
		if (checkCol(i) != ' ') {
			return checkCol(i);
		}
		
	}
	if (checkDiag(1) != ' ') {
		return checkDiag(1);
	}

	if (checkDiag(2) != ' ') {
		return checkDiag(2);
	}

	return ' ';
}

char checkRow(int r) {
	int firstChar = gameBoard[r][0];
	if (firstChar == ' ') {
		return ' ';
	}
	for (int i=1; i<gameBoardSize; i++) {
		if ( gameBoard[r][i] != firstChar) {
			return ' ';
		}
	}
	return firstChar;
}

char checkCol(int c) {
	int firstChar = gameBoard[0][c];
	if (firstChar == ' ') {
		return ' ';
	}
	for (int i=1; i<gameBoardSize; i++) {
		if ( gameBoard[i][c] != firstChar) {
			return ' ';
		}
	}
	return firstChar;

}

char checkDiag(int d) {
	if (d == 1) {
		int firstChar = gameBoard[0][0];
		if (firstChar == ' ') {
			return ' ';
		}
		for (int i=0; i<gameBoardSize; i++) {
			if ( gameBoard[i][i] != firstChar) {
				return ' ';
			}
		}
		return ' ';
	}
	if (d == 2) {
		int firstChar = gameBoard[gameBoardSize][0];
		if (firstChar == ' ') {
			return ' ';
		}
		for (int i=0; i<gameBoardSize; i++) {
			if ( gameBoard[gameBoardSize-i][i] != firstChar) {
				return ' ';
			}
		}
		return ' ';
	}

}

void initGameBoard(){
	for (int x=0; x<gameBoardSize; x++) {
		for (int y=0; y<gameBoardSize; y++) {
			gameBoard[x][y] = ' ';
		}
	}
}

void updatePosition(int x, int y, char player) {
	gameBoard[x][y] = player;
}
