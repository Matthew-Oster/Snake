#pragma once
#include <utility>
#include "snake.h"

#ifndef BOARD_FORMAT
#define LINE_WIDTH 6
#define BLOCK_SIZE 16
#define BOARD_POSITION 360
#define BOARD_HEIGHT 30
#define BOARD_WIDTH 30
#define MIN_HORIZONTAL_MARGIN 20
#define MIN_VERTICAL_MARGIN 40
#endif

class Board {
public:
	Board() { 
		initBoard(); 
	}

	// Puts new apple on the board and sets apple_Pos
	void generateApple();
	// Getter for apple_Pos
	std::pair<int, int> getApplePos() { return apple_Pos; }
	// "Stamps" snake's position on the board

	static int board[BOARD_HEIGHT][BOARD_WIDTH];

private:
	// Board setup
	void initBoard(); 

	std::pair<int, int> apple_Pos; // (Y, X) coordinates for apple position
};
