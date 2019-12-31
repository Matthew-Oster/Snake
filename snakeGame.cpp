#include "snakeGame.h"
#include <iostream>

int leftBorder = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2));
int rightBorder = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
int yMargin = MIN_VERTICAL_MARGIN;

void Game::DrawScene() {
	DrawBoard();
	DrawObjects();
}

void Game::makeGrow() {
	auto head_pos = player->getPosList()->begin();
	auto apple_pos = mBoard->getApplePos();

	if (head_pos->first == apple_pos.first && head_pos->second == apple_pos.second) {
		player->grow();
		mBoard->generateApple();
	}
}

void Game::gameOver() {

	// Paint red 'X' on screen
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			mIO->DrawRectangle(leftBorder + (j * BLOCK_SIZE), yMargin + (i * BLOCK_SIZE), BLOCK_SIZE, BLOCK_SIZE, RED, true);
		}
	}

	mIO->loadMedia("gameOver.png");
	mIO->ClearScreen();
	DrawScene();
	mIO->UpdateScreen();

	SDL_Delay(2000);
	mIO->endGame();
}

void Game::DrawBoard() {
	// left border
	mIO->DrawRectangle(leftBorder - LINE_WIDTH, yMargin, LINE_WIDTH, (mIO->GetScreenHeight() * 2/3), WHITE, true);
	// right border
	mIO->DrawRectangle(rightBorder, yMargin, LINE_WIDTH, (mIO->GetScreenHeight() * 2/3), WHITE, true);
	// top border
	mIO->DrawRectangle(leftBorder - LINE_WIDTH, yMargin - LINE_WIDTH, rightBorder - leftBorder + (LINE_WIDTH * 2), LINE_WIDTH, WHITE, true);
	// bottom border
	mIO->DrawRectangle(leftBorder - LINE_WIDTH, yMargin + (mIO->GetScreenHeight() * 2 / 3), rightBorder - leftBorder + (LINE_WIDTH * 2), LINE_WIDTH, WHITE, true);
}

void Game::DrawObjects() {
	for (auto snakeIt = player->getPosList()->cbegin(); snakeIt != player->getPosList()->cend(); snakeIt++) 
		mBoard->board[snakeIt->first][snakeIt->second] = 1;

	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			// Draw Apple
			if (mBoard->board[i][j] == 3)
				mIO->DrawRectangle(leftBorder + (j * BLOCK_SIZE), yMargin + (i * BLOCK_SIZE), BLOCK_SIZE, BLOCK_SIZE, RED, true);
			// Draw Snake
			else if (mBoard->board[i][j] == 1)
				mIO->DrawRectangle(leftBorder + (j * BLOCK_SIZE), yMargin + (i * BLOCK_SIZE), BLOCK_SIZE, BLOCK_SIZE, GREEN, true);
		}
	}

}