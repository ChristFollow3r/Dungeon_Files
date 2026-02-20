#pragma once
#include "libraries.h"

struct Position {
	int x;
	int y;
};

void PlayerMovement(std::vector<std::vector<char>>& dungeon, Position &playerPosition, int& points);