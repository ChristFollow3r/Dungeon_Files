#pragma once
#include "libraries.h"

std::vector<std::vector<char>> CreateDungeon();
void PlaceChests(&std::vector<std::vector<char>> dungeon);
void PrintDungeon(std::vector<std::vector<char>> dungeon);