#include "files.h"


// This function requires some proper explanation I think cause it took me a while to do this.
// I ask the user if he wants to use a custom file for the dungeon, if he says no, then the program
// proceeds to run a function to generate a dungeon inide the program. If he says yes I open the file
// with the reading flag, I get each line of the file and I do a for each loop for every char inside the string
// and i push it to the vector of vectors.
// Either way it returns a vector of vectors called dungeon.

std::vector<std::vector<char>> CreateOrNotDungeonWithFile() {

	std::vector<std::vector<char>> dungeon;
	std::string line;
	char input;

	std::cout << "Do you want to use a file to generate the dungeon (Y) / (N): ";
	std::cin >> input;

	if (input == 'n' || input == 'N') {
		dungeon = CreateDungeon();
		return dungeon;
	}

	else {

		std::ifstream dungeonFile("dungeonFile.txt", std::ios::in);

		if (!dungeonFile.is_open()) {
			std::cout << "Couldn't open the file. The program will generate the dungeon...";
			dungeon = CreateDungeon();
			return dungeon;
		}

		while (std::getline(dungeonFile, line)) {

			std::vector<char> row;

			for (char x : line) {
				row.push_back(x);
			}

			dungeon.push_back(row);
		}

		return dungeon;
	}
}