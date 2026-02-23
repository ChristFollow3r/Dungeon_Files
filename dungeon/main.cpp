#include <iostream>
#include "dungeon.h"
#include "gameplay.h"
#include "libraries.h"

int main() {

	srand(time(NULL));
	Position playerPosition;
	int winChance = 30; // A ver profe com que un item del archiu items.txt? Que he de fer crear un txt amb una lletra dins?

	std::vector<std::vector<char>> dungeon = CreateOrNotDungeonWithFile();
	PlaceChests(dungeon);
	PlaceEnemies(dungeon);

	playerPosition.x = dungeon.size() / 2;
	playerPosition.y = dungeon.size() / 2;
	dungeon[playerPosition.x][playerPosition.y] = 'P';

	int money = rand() % 200;

	while (true) {

		PrintDungeon(dungeon);
		std::cout << "Your budget: " << money << "\n";
		PlayerMovement(dungeon, playerPosition, money, winChance);

	}

	return 1;
}