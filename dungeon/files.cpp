#include "files.h"


// This function requires some proper explanation I think cause it took me a while to do this.
// I ask the user if he wants to use a custom file for the dungeon, if he says no, then the program
// proceeds to run a function to generate a dungeon inide the program. If he says yes I open the file
// with the reading flag, I get each line of the file and I do a for each loop for every char inside the string
// and i push it to the vector of vectors.
// Either way it returns a vector of vectors called dungeon.

std::pair<bool, std::vector<std::vector<char>>> CreateOrNotDungeonWithFile() {

	std::vector<std::vector<char>> dungeon;
	std::string line;
	char input;

	std::cout << "Do you want to use a file to generate the dungeon (Y) / (N): ";
	std::cin >> input;

	if (input == 'n' || input == 'N') {
		dungeon = CreateDungeon();
		return { 0, dungeon };
	}

	else {

		std::ifstream dungeonFile("dungeonFile.txt", std::ios::in);

		if (!dungeonFile.is_open()) {
			std::cout << "Couldn't open the file. The program will generate the dungeon...";
			dungeon = CreateDungeon();
			return {0,dungeon };
		}

		while (std::getline(dungeonFile, line)) {

			std::vector<char> row;

			for (char x : line) {
				if (x == '.') x = ' ';
				row.push_back(x);
			}

			dungeon.push_back(row);
		}
		dungeonFile.close();
		return { 1,dungeon };
	}
}

void SaveAndExitGame(std::vector<std::vector<char>>& dungeon, Position playerPosition, int money, int winChance, int playerHealth, bool bomb, bool gamblingCoin) { 

	std::fstream file("savedGame.bin", std::ios::out | std::ios::binary);
	std::string input;

	std::cout << "Do you want to save and exit the game? (Y) / (N)\n";
	std::cin >> input;

	if (input == "n" || input == "N") return;

	if (!file.is_open()) {
		system("cls");
		std::cout << "Couldn't open the file. That's a you problem.";
		system("pause");
		return;
	}

	file.write(reinterpret_cast<char*>(&playerPosition), sizeof(Position));
	file.write(reinterpret_cast<char*>(&money), sizeof(int));
	file.write(reinterpret_cast<char*>(&winChance), sizeof(int));
	file.write(reinterpret_cast<char*>(&playerHealth), sizeof(int));
	file.write(reinterpret_cast<char*>(&bomb), sizeof(bool));
	file.write(reinterpret_cast<char*>(&gamblingCoin), sizeof(bool));

	for (int i = 0; i < dungeon.size(); i++)
	{
		int temp = dungeon[i].size(); 

		file.write(reinterpret_cast<char*>(&temp), sizeof(int)); // Write first the length of the row
		for (char x : dungeon[i]) file.write(reinterpret_cast<char*>(&x), sizeof(char)); // Write the row content

	}

	file.close();
	system("cls");
	std::cout << "See you soon brave adventurer!";
	exit(0);

}

void GetItemsFromFile(std::vector<Item>& avalibleItems) {

	std::fstream file("items.txt", std::ios::in);
	std::string line;
	std::vector<std::string> itemInfo;

	if (!file.is_open()) {
		system("cls");
		std::cout << "Couldn't open items.txt file.";
		system("pause");
		exit(0);
	}

	while (std::getline(file, line)) {
		itemInfo.push_back(line);
	}

	file.close();

	while (!itemInfo.empty()) {

		Item* item = new Item;

		for (int i = 0; i < 4; i++)
		{
			switch (i) {

			case (0):
				item->name = itemInfo[i];
				break;
			case (1):
				item->price = stoi(itemInfo[i]);
				break;
			case (2):
				item->winChance = stoi(itemInfo[i]);
			case (3):
				item->description = itemInfo[i];
				break;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			itemInfo.erase(itemInfo.begin());
		}

		avalibleItems.push_back(*item);
		delete(item); // Fixes memory leak issues. I think.
	}
	

}


std::vector<std::vector<char>> LoadDungeonWithBinary(Position& playerPosition, int& money, int& winChance, int& playerHealth, bool& bomb, bool& gamblingCoin) {

	std::fstream file("savedGame.bin", std::ios::in | std::ios::binary);
	std::vector<std::vector<char>> dungeon;

	int rowLength;
	std::string row;
	char temp;

	// bruh
	Position loadedPlayerPosition;
	int loadedMoney;
	int loadedWinchance;
	int loadedPlayerHealth;
	bool loadedBomb;
	bool loadedGamblingCoin;

	if (!file.is_open()) {
		system("cls");
		std::cout << "Your file couldn't be opened.\n";
		exit(0);
	}

	file.read(reinterpret_cast<char*>(&loadedPlayerPosition), sizeof(Position)); // Load all the player stuf...
	playerPosition = loadedPlayerPosition;

	file.read(reinterpret_cast<char*>(&loadedMoney), sizeof(int));
	money = loadedMoney;

	file.read(reinterpret_cast<char*>(&loadedWinchance), sizeof(int));
	winChance = loadedWinchance;

	file.read(reinterpret_cast<char*>(&loadedPlayerHealth), sizeof(int));
	playerHealth = loadedPlayerHealth;

	file.read(reinterpret_cast<char*>(&loadedBomb), sizeof(bool));
	bomb = loadedBomb;

	file.read(reinterpret_cast<char*>(&loadedGamblingCoin), sizeof(bool));
	gamblingCoin = loadedGamblingCoin;

	while (file.read(reinterpret_cast<char*>(&rowLength), sizeof(int))) { // The idea is that before reading the chars of each row, the binary must conatin
																		 // the number of chars that row has.

		std::vector<char> tempVector;
		row.resize(rowLength);
		
		for (int i = 0; i < rowLength; i++)
		{
			file.read(reinterpret_cast<char*>(&temp), sizeof(char));
			row[i] = temp;
		}

		for (char x : row) tempVector.push_back(x);
		dungeon.push_back(tempVector);
	}
	file.close();

	return dungeon;
}