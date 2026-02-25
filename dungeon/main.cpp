#include <iostream>
#include "dungeon.h"
#include "gameplay.h"
#include "libraries.h"
#include "inventory.h"

int main() {

	srand(time(NULL));
	Position playerPosition;
	int playerHealth = rand() % 6;
	int winChance = 30;
	bool bomb = false;
	bool gamblingCoin = false;
	std::vector<Item> avalibleItems;

	if (playerHealth == 0) {
		system("cls");
		std::cout << "That's some solid bad luck you have mate!\n";
		std::cout << "The fates didnt want you playing today... You are already dead!\n";
		std::cout << "Try it again if you dare to defy the fates.\n";
		system("pause");
		exit(0);
	}

	std::vector<std::vector<char>> dungeon = CreateOrNotDungeonWithFile();
	GetItemsFromFile(avalibleItems);
	PlaceChests(dungeon);
	PlaceEnemies(dungeon);

	playerPosition.x = dungeon.size() / 2;
	playerPosition.y = dungeon.size() / 2;
	dungeon[playerPosition.x][playerPosition.y] = 'P';

	int money = rand() % 200;

	while (true) {

		PrintDungeon(dungeon);
		std::cout << "Your budget: " << money << "\n";
		std::cout << "Your health: " << playerHealth << "\n";
		std::cout << "(K) Bomb: " << bomb << "\n";
		std::cout << "(G) Gambling coin: " << gamblingCoin << "\n";
		/// Crec que tenir tot el joc a aquesta funció es una mica MOLT mala pràctica, pero bueno ja està fet :V
		PlayerMovement(dungeon, playerPosition, money, winChance, playerHealth, avalibleItems, bomb, gamblingCoin);

	}

	return 1;
}