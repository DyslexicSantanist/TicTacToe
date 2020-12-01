#include <iostream>
#include <limits>
using namespace std;

//int chooseSymbol();
void turn();
void draw();
int checkWinner();
void reset();

int player = 0; //turn state
int gameBoard[3][3];

/*
int chooseSymbol() { 
	while (true) {
		cout << "Choose your symbol, player 1" << endl << "0 for O or 1 for X" << endl;
		cin >> symbolChoice;
		switch (symbolChoice){
			case 0:
				cout << "Player 1 is " << symbol[0] << endl;
				cout << "Player 2 is " << symbol[1] << endl;
				return 0;
			case 1:
				cout << "Player 1 is " << symbol[1] << endl;
				cout << "Player 2 is " << symbol[0] << endl;
				return 1;
		}
		cout << "ERROR: Invalid input" << endl;
		continue;
	}
}
*/

void draw() {
	system("CLS");
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j++) {
			switch (gameBoard[i][j]) {
				case 25:
					cout << 'X' << " ";
					break;
				case 80:
					cout << 'O' << " ";
					break;
				default:
					cout << gameBoard[i][j] << " "; 
			}
		}		
		cout << endl;
	}
}

void turn() {
	cout << endl << "It is player " << player % 2 << "'s turn" << endl;
	int square;
	while (true) {
		cout << "Choose an available square using a number from 1 to 9" << endl;
		cin >> square;
		square--;

		if (cin.fail()) {
			cout << "ERROR: Non-integer entered. Please enter a number from 1 to 9" << endl;
			continue;
		}
		
		else if (square < 0 || square > 8) {
			cout << "Your input is out of bounds" << endl;
			continue;
		}
		
		else if (gameBoard[square/3][square%3] > 10) {
			draw();
			cout << "Error: The square you have chosen is taken. Choose another square" << endl;
			continue;
		}
	
		else if (square >= 0 && square < 9) {
			switch (player % 2){
				case 0:
					gameBoard[square / 3][square % 3] = 80;
					break;
				case 1:
					gameBoard[square / 3][square % 3] = 25;
					break;
			}
			break;
		}
		else {
			cout << "UNRESOLVED ERROR, CONTACT DEVELOPER, MISTAKES WERE MADE, THE END TIMES ARE UPON US" << endl;
		}
	}
	player++;
}

int checkWinner() {
	char replay[1];
	for (int i = 0; i < 3; i++) {
		if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
			cout << "Player " << player % 2 << " won" << endl;
			cout << "Play again? <Y/N>"  << endl;
			cin >> replay[0];
			if (replay[0] == 'Y' || replay[0] == 'y') {
				reset();
			}
			else {
				cout << "Game Terminated.";
			}
			return 1;
		}
	}
	for (int j = 0; j < 3; j++) {
		if (gameBoard[0][j] == gameBoard[1][j] && gameBoard[1][j] == gameBoard[2][j]) {
			cout << "Player " << player % 2 << " won" << endl;
			cout << "Play again? <Y/N>"  << endl;
			cin >> replay[0];
			if (replay[0] == 'Y' || replay[0] == 'y') {
				reset();
			}
			else {
				cout << "Game Terminated.";
			}
			return 1;
		}
	}
	if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
		cout << "Player " << player % 2 << " won" << endl; 
		cout << "Play again? <Y/N>"  << endl;
		cin >> replay[0];
		if (replay[0] == 'Y' || replay[0] == 'y') {
			reset();
		}
		else {
			cout << "Game Terminated.";
		}
		return 1;
	}
	if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
		cout << "Player " << player % 2 << " won" << endl;
		cout << "Play again? <Y/N>"  << endl;
		cin >> replay[0];
		if (replay[0] == 'Y' || replay[0] == 'y') {
			reset();
		}
		else {
			cout << "Game Terminated.";
		}
		return 1;
	}

	return 0;
}

void reset() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			gameBoard[i][j] = (i * 3) + j + 1;
		}
	}
	player = 0;
}

int main() {
	//chooseSymbol();
	reset();
	draw();

	while (true) {
		turn();
		draw();
		checkWinner();
	}
}

//choosing your symbol
//reset
//play again
//better congratulations

