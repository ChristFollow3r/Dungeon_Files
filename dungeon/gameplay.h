#pragma once
#include "libraries.h"

/// <summary>
/// It's a vector 2
/// </summary>
struct Position {
	int x;
	int y;
};

/// <summary>
/// Move the player inside the dungeon and other stuff (like getting money from chests)
/// </summary>
/// <param name="dungeon">The 2D grid</param>
/// <param name="playerPosition">The player position</param>
/// <param name="points">The amount of points the player has</param>
void PlayerMovement(std::vector<std::vector<char>>& dungeon, Position &playerPosition, int& points, int& winChance);