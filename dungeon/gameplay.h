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
/// Adds points (currency) and adds to the winChance variable
/// </summary>
/// <param name="points">The amount of money the player has</param>
/// <param name="winChance">The chances the player has to win a combat</param>
void AddPoints(int& points, int& winChance);
/// <summary>
/// Allows the player to escape the dungeon without fighting
/// </summary>
/// <param name="points">The amount of money the player has</param>
void EscapeDungeon(int& points);
/// <summary>
/// Randomly places a 'P' inside the dungeon if the player exits the shop
/// </summary>
/// <param name="dungeon"></param>
void FindShop(std::vector<std::vector<char>>& dungeon);
/// <summary>
/// Move the player inside the dungeon and other stuff (like getting money from chests)
/// </summary>
/// <param name="dungeon">The 2D grid</param>
/// <param name="playerPosition">The player position</param>
/// <param name="points">The amount of points the player has</param>
void PlayerMovement(std::vector<std::vector<char>>& dungeon, Position &playerPosition, int& points, int& winChance);