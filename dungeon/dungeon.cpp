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

void PrintDungeon(std::vector<std::vector<char>> dungeon) {

	for (int i = 0; i < dungeon.size(); i++)
	{
		for (int j = 0; j < dungeon.size(); j++)
		{
			std::cout << dungeon[i][j] << " ";
		}std::cout << "\n";
	}
}