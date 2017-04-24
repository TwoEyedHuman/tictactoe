#include <iostream>
#include <map>
//Global variables
const int gameBoardSize = 3; //for an nxn board
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
	initGameBoard(); //initialize game board
	int usrinx, usriny; //user input

	std::map<int, char> player; //translate player int to ID, used with move count
	int playerCnt; //number of players
	char bufPlayerID; //buffer to hold player IDs
	std::cout << "Player Count: ";
	std::cin >> playerCnt;

	//grab player ID and load into the player map
	for (int i=0; i<playerCnt; i++) {
		std::cout << "Player ID: ";
		std::cin >> bufPlayerID;
		player[i]=bufPlayerID;
	}

	int moveCnt = 0; //keep track of how many moves have occurred
	while (winner() == ' ') {
		printBoard();
		std::cout << player[moveCnt % playerCnt] << "(x y): "; 
		std::cin >> usrinx;
		std::cin >> usriny;
		updatePosition(usrinx, usriny, player[moveCnt % playerCnt]);
		moveCnt++;
	}

	printBoard();
	std::cout << "Player " << winner() << " wins!" << std::endl;

	return 0;
}

void printBoard() {
	for (int i=0; i<gameBoardSize; i++) {
		for (int j=0; j<gameBoardSize-1; j++) {
			std::cout << " " << gameBoard[i][j] << " |";
		}
		std::cout << " " << gameBoard[i][gameBoardSize-1] << std::endl;
		for (int j=0; j<4*(gameBoardSize-1) + 3; j++) {
			std::cout << "-";
		}
		std::cout <<  std::endl;
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
		return firstChar;
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
		return firstChar;
	}
	return ' ';
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
