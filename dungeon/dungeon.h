#pragma once
#include "libraries.h"

/// <summary>
/// Creates the dungeon where the player will play
/// </summary>
/// <returns>2D vector of chars</returns>
std::vector<std::vector<char>> CreateDungeon();
/// <summary>
/// Place chests randomly in the dungeon
/// </summary>
/// <param name="dungeon">The 2D grid where the game takes place</param>
void PlaceChests(std::vector<std::vector<char>>& dungeon);
void PlaceEnemies(std::vector<std::vector<char>>& dungeon);
/// <summary>
/// Prints the dungeon to the console
/// </summary>
/// <param name="dungeon">The 2D grid where the game takes place</param>
void PrintDungeon(std::vector<std::vector<char>> dungeon);