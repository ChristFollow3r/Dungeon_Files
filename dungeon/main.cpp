#include <iostream>
#include "dungeon.h"
#include "libraries.h"

int main() {

	std::vector<std::vector<char>> dungeon = CreateDungeon();
	PlaceChests(dungeon);
	PrintDungeon(dungeon);
	return 1;
}