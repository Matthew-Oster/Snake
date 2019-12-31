#pragma once
#include "snakeBoard.h"
#include "snake.h"
#include "IO.h"
#include <utility>

class Game {
public:
	Game(Board* pBoard, Snake* pSnake, IO* pIO) :
		mBoard(pBoard), player(pSnake), mIO(pIO) {}

	void DrawScene();
	void makeGrow();
	void gameOver();

	Board* mBoard = NULL;
	Snake* player = NULL;
	IO* mIO = NULL;

private:
	
	void DrawBoard();
	void DrawObjects();
};