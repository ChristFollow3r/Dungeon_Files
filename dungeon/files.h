#pragma once
#include "libraries.h"

/// <summary>
/// This function allows the user to chose between openning a txt to have a custom dungeon or use the program function to make a dungeon
/// </summary>
/// <returns>2D vector (The dungeon grid)</returns>
std::vector<std::vector<char>> CreateOrNotDungeonWithFile();
