// Snake Behavior
#pragma once
#include <utility>
#include <vector>
#include <SDL.h>

#ifndef BOARD_FORMAT
#define LINE_WIDTH 6
#define BLOCK_SIZE 16
#define BOARD_POSITION 360
#define BOARD_HEIGHT 30
#define BOARD_WIDTH 30
#define MIN_HORIZONTAL_MARGIN 20
#define MIN_VERTICAL_MARGIN 40
#endif

class Snake {
public:
	Snake() {
		position_list.push_back(std::make_pair(BOARD_HEIGHT/2, BOARD_WIDTH/2));
		position_list.push_back(std::make_pair(BOARD_HEIGHT/2, BOARD_WIDTH/2 + 1));
		position_list.push_back(std::make_pair(BOARD_HEIGHT/2, BOARD_WIDTH/2 + 2));
	}

	const std::vector<std::pair<int, int>> *getPosList() const { return &position_list; }

	// Adjusts the snake's coordinates in position_list, effectively moving it.
	// Returns position to be erased. (Passed to updateBoard)
	std::pair<int,int> move(int &keyNum, int prevKey);

	bool isCollision(int yPos, int xPos);
	void grow();

private:
	std::vector<std::pair<int, int>> position_list;
};