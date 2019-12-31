#include "snakeGame.h"
#include <SDL.h>
#include <random>
#include <time.h>
#include <iostream>
#include <utility>
#include <vector>

int main(int argc, char** argv) {
	srand(time(NULL));
	IO mIO;
	Board myBoard;
	Snake player;
	std::pair<int, int> tail;
	Game mGame(&myBoard, &player, &mIO);
	const std::vector<std::pair<int, int>>* position_list;
	int mKey, prevKey = SDLK_LEFT;	// prevKey remembers the most recent key pressed

	while (!mIO.IsKeyDown(SDLK_ESCAPE)) {
		mIO.ClearScreen();
		mGame.DrawScene();
		mIO.UpdateScreen();

		mKey = mIO.PollKey();

		if (mKey == -1) tail = player.move(prevKey, prevKey); // if player doesn't input a direction
		else tail = player.move(mKey, prevKey);	// if player inputs a direction
		mGame.makeGrow();

		myBoard.board[tail.first][tail.second] = 0;
		position_list = player.getPosList();
		auto positionIt = position_list->begin();
		
		// Check if collision occured
		if (player.isCollision(positionIt->first, positionIt->second)) {
			mGame.gameOver();
			return 0;
		}

		SDL_Delay(75);
		if(mKey != -1) prevKey = mKey; // only updates if player inputs direction
	}

	return 0;
}