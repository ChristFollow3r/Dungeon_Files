#include <iostream>
#include "dungeon.h"
#include "gameplay.h"
#include "libraries.h"

int main() {

	srand(time(NULL));
	Position playerPosition;

	std::vector<std::vector<char>> dungeon = CreateDungeon();
	PlaceChests(dungeon);

	playerPosition.x = dungeon.size() / 2;
	playerPosition.y = dungeon.size() / 2;
	dungeon[playerPosition.x][playerPosition.y] = 'P';

	int points = rand() % 200;

	while (true) {

		PrintDungeon(dungeon);
		std::cout << "Your budget: " << points << "\n";
		PlayerMovement(dungeon, playerPosition);

	}

	return 1;
}