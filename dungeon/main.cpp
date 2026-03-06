#include <iostream>
#include "dungeon.h"
#include "gameplay.h"
#include "libraries.h"
#include "inventory.h"

int main() {

	srand(time(NULL));

	Position playerPosition;

	int money = rand() % 200;
	int winChance = 30;
	int playerHealth = rand() % 6;

	bool bomb = false;
	bool gamblingCoin = false;
	bool askForBinary = true;

	char answer;

	std::vector<Item> avalibleItems;
	std::vector<std::vector<char>> dungeon;


	std::cout << "Do you want to use a binary file to load a dungeon (y/n): \n";
	std::cin >> answer;
	if (answer == 'n') askForBinary = false;


	if (!askForBinary) {
		dungeon = CreateOrNotDungeonWithFile();
		PlaceChests(dungeon);
		PlaceEnemies(dungeon);
		playerPosition.x = dungeon.size() / 2;
		playerPosition.y = dungeon.size() / 2;
		dungeon[playerPosition.x][playerPosition.y] = 'P';
	}
	else dungeon = LoadDungeonWithBinary(playerPosition, money, winChance, playerHealth, bomb, gamblingCoin);

	GetItemsFromFile(avalibleItems);

	if (playerHealth == 0) {
		system("cls");
		std::cout << "That's some solid bad luck you have mate!\n";
		std::cout << "The fates didnt want you playing today... You are already dead!\n";
		std::cout << "Try it again if you dare to defy the fates.\n";
		system("pause");
		exit(0);
	}



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