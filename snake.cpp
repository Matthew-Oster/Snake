#include "snake.h"
#include <utility>
#include <vector>
#include <iostream>

std::pair<int, int> Snake::move(int &keyNum, int prevKey) {

	auto tail_val = *(position_list.end() - 1);
	auto positionIt = position_list.end() - 1;
	for (positionIt; positionIt != position_list.begin(); positionIt--) {
		*positionIt = *(positionIt - 1);	// all non-head segments follow path
	}
	positionIt = position_list.begin();

	switch (keyNum)
	{
	case (SDLK_UP): {
		if (prevKey == SDLK_DOWN) {
			keyNum = SDLK_DOWN;
			*positionIt = std::make_pair(positionIt->first + 1, positionIt->second);	// head segment moves down
		//	if (isCollision(positionIt->first, positionIt->second)) exit(0);
			return tail_val;
		}
		*positionIt = std::make_pair(positionIt->first - 1, positionIt->second); // head segment moves up
		// (isCollision(positionIt->first, positionIt->second)) exit(0);
		return tail_val;
	}
	case (SDLK_DOWN): {
		if (prevKey == SDLK_UP) {
			keyNum = SDLK_UP;
			*positionIt = std::make_pair(positionIt->first - 1, positionIt->second);	// head segment moves down
			// (isCollision(positionIt->first, positionIt->second)) exit(0);
			return tail_val;
		}
		*positionIt = std::make_pair(positionIt->first + 1, positionIt->second);	// head segment moves down
		//if (isCollision(positionIt->first, positionIt->second)) exit(0);
		return tail_val;
	}
	case (SDLK_RIGHT): {
		if (prevKey == SDLK_LEFT) {
			keyNum = SDLK_LEFT;
			*positionIt = std::make_pair(positionIt->first, positionIt->second - 1);	// head segment moves down
			//if (isCollision(positionIt->first, positionIt->second)) exit(0);
			return tail_val;
		}
		*positionIt = std::make_pair(positionIt->first, positionIt->second + 1);	// head segment moves right
		//if (isCollision(positionIt->first, positionIt->second)) exit(0);
		return tail_val;
	}
	case (SDLK_LEFT):
		if (prevKey == SDLK_RIGHT) {
			keyNum = SDLK_RIGHT;
			*positionIt = std::make_pair(positionIt->first, positionIt->second + 1);	// head segment moves down
		//	if (isCollision(positionIt->first, positionIt->second)) exit(0);
			return tail_val;
		}
		*positionIt = std::make_pair(positionIt->first, positionIt->second - 1);	// head segment moves left
	//	if (isCollision(positionIt->first, positionIt->second)) exit(0);
		return tail_val;
	}

	return tail_val;
}

bool Snake::isCollision(int yPos, int xPos) {
	if (yPos > 29 || yPos < 0 || xPos > 29 || xPos < 0) return true;
	for (auto i = position_list.begin() + 1; i != position_list.end(); i++)
		if (yPos == i->first && xPos == i->second) return true;
	return false;
}

void Snake::grow() {
	if (!isCollision((position_list.end() - 1)->first, (position_list.end() - 1)->second + 1))
		position_list.push_back(std::make_pair((position_list.end() - 1)->first, (position_list.end() - 1)->second + 1));
	else if (!isCollision((position_list.end() - 1)->first, (position_list.end() - 1)->second - 1))
		position_list.push_back(std::make_pair((position_list.end() - 1)->first, (position_list.end() - 1)->second - 1));
	else if (!isCollision((position_list.end() - 1)->first + 1, (position_list.end() - 1)->second))
		position_list.push_back(std::make_pair((position_list.end() - 1)->first + 1, (position_list.end() - 1)->second));
	else if (!isCollision((position_list.end() - 1)->first - 1, (position_list.end() - 1)->second))
		position_list.push_back(std::make_pair((position_list.end() - 1)->first - 1, (position_list.end() - 1)->second));
}