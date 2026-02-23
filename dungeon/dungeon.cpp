#include "libraries.h"

std::vector<std::vector<char>> CreateDungeon() {
	
	std::string input;
	int size;
	std::vector<std::vector<char>> dungeon;

	while (true) {

		std::cout << "Enter how big do you want the dungeon to be: ";
		std::cin >> input;

		size = stoi(input);

		if (size > 0) break;
	}

	for (int i = 0; i <= size; i++)
	{
		std::vector<char> row;

		for (int j = 0; j <= size; j++)
		{
			if (i == 0 || i == size || j == 0 || j == size) row.push_back('#');
			else row.push_back(' ');
		}

		dungeon.push_back(row);
	}

	return dungeon;
}

void PlaceChests(std::vector<std::vector<char>>& dungeon) {

	std::string input;
	int amount = -1;
	int x;
	int y;


	while (amount < 0 || amount >= (dungeon.size() / 1.5)) {

	std::cout << "How many chests do you want the dungeon to have: ";
	std::cin >> input;

	amount = stoi(input);

	}

	for (int i = 0; i < amount + 1; i++) {

		//while (x <= 2 || x >= dungeon.size() - 2 && y <= 2 || y >= dungeon.size() - 2); No se perquè això no em funciona be

		x = rand() % dungeon.size();
		y = rand() % dungeon.size();

		if (x == 0) x += 1;
		else if (x == dungeon.size() - 1) x -= 1;

		if (y == 0) y += 1;
		else if (y == dungeon.size() - 1) y -= 1;


		if (i == amount) dungeon[x][y] = 'S';
		else if (i != amount) dungeon[x][y] = 'C';
	}

}


void PlaceEnemies(std::vector<std::vector<char>>& dungeon) {

	int amount = dungeon.size() + 5; // Perquè si :V Magic number que flipas per la cara
	int x;
	int y;

	for (int i = 0; i < amount + 1; i++) {


		x = rand() % dungeon.size();
		y = rand() % dungeon.size();

		if (x == 0) x += 1;
		else if (x == dungeon.size() - 1) x -= 1;

		if (y == 0) y += 1;
		else if (y == dungeon.size() - 1) y -= 1;

		if (dungeon[x][y] == 'C' || dungeon[x][y] == 'P' || dungeon[x][y] == 'S') {
			amount--;
			continue;
		}

		dungeon[x][y] = 'E';
	}
}

void PrintDungeon(std::vector<std::vector<char>> dungeon) {

	system("cls");

	for (int i = 0; i < dungeon.size(); i++)
	{
		for (int j = 0; j < dungeon[i].size(); j++) // Marti això mho vas dir tu (dungeon[i])
		{
			std::cout << dungeon[i][j] << " ";
		}
		std::cout << "\n";
	}

}