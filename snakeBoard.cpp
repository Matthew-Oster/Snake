#include "snakeBoard.h"
#include <iostream>
#include <random>
#include <utility>
#include <vector>

int Board::board[BOARD_HEIGHT][BOARD_WIDTH]; // must declare static member in .cpp file

void Board::initBoard() {
	for (int i = 0; i < BOARD_HEIGHT; i++)
		for (int j = 0; j < BOARD_WIDTH; j++)
			board[i][j] = 0;

	generateApple();
}

void Board::generateApple() {
	int appleY_Pos = rand() % BOARD_HEIGHT;
	int appleX_Pos = rand() % BOARD_WIDTH;
	bool good_Pos = false;

	// ensure apple is always at least 2 spaces away
	while (!good_Pos) {
		if (board[appleY_Pos][appleX_Pos] != 0) {
			appleY_Pos = rand() % BOARD_HEIGHT;
			appleX_Pos = rand() % BOARD_WIDTH;
		}
		else if ((appleY_Pos >= BOARD_HEIGHT) || (appleY_Pos <= 0))
			appleY_Pos = rand() % BOARD_HEIGHT;
		else if ((appleX_Pos >= BOARD_WIDTH) || (appleX_Pos <= 0))
			appleX_Pos = rand() % BOARD_WIDTH;
		else if ((board[appleY_Pos+1][appleX_Pos] != 0) || (board[appleY_Pos-1][appleX_Pos] != 0))
			appleY_Pos = rand() % BOARD_HEIGHT;
		else if ((board[appleY_Pos][appleX_Pos+1] != 0) || (board[appleY_Pos][appleX_Pos-1] != 0))
			appleY_Pos = rand() % BOARD_HEIGHT;
		else good_Pos = true;
	}

	board[appleY_Pos][appleX_Pos] = 3;
	apple_Pos = std::make_pair(appleY_Pos, appleX_Pos);

	std::cout << "\nApple at: (Y = " << apple_Pos.first << ", X = " << apple_Pos.second << "\n";
}