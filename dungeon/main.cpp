#include <iostream>
#include "dungeon.h"
#include "libraries.h"

int main() {

	std::vector<std::vector<char>> dungeon = CreateDungeon();
	PrintDungeon(dungeon);
	return 1;
}