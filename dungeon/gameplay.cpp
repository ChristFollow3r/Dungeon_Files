#include "libraries.h"
#include "gameplay.h"

void PlayerMovement(std::vector<std::vector<char>>& dungeon, Position& playerPosition, int& points) {

	std::string input;
	char direction;

	std::cout << "Up (W), Down (S), Left (A), Right (D), Exit (E): ";
	std::cin >> input;

	if (input == "w") input = "W";
	else if (input == "s") input = "S";
	else if (input == "a") input = "A";
	else if (input == "d") input = "D";
	else if (input == "e") input = "E";
	else return;

	direction = input[0];

	switch (direction) {

		case ('W') :
			if (dungeon[playerPosition.x - 1][playerPosition.y] == '#') break;
			else if ((dungeon[playerPosition.x - 1][playerPosition.y] == 'C')) points += 50;
			else if ((dungeon[playerPosition.x - 1][playerPosition.y] == 'C'))
			dungeon[playerPosition.x - 1][playerPosition.y] = 'P';
			dungeon[playerPosition.x][playerPosition.y] = ' ';
			playerPosition.x -= 1;
			break;

		case ('S'):
			if (dungeon[playerPosition.x + 1][playerPosition.y] == '#') break;
			else if ((dungeon[playerPosition.x + 1][playerPosition.y] == 'C')) points += 50;
			dungeon[playerPosition.x + 1][playerPosition.y] = 'P';
			dungeon[playerPosition.x][playerPosition.y] = ' ';
			playerPosition.x += 1;
			break;

		case ('A'):
			if (dungeon[playerPosition.x][playerPosition.y - 1] == '#') break;
			else if ((dungeon[playerPosition.x][playerPosition.y - 1] == 'C')) points += 50;
			dungeon[playerPosition.x][playerPosition.y - 1] = 'P';
			dungeon[playerPosition.x][playerPosition.y] = ' ';
			playerPosition.y -= 1;
			break;

		case ('D'):
			if (dungeon[playerPosition.x][playerPosition.y + 1] == '#') break;
			else if ((dungeon[playerPosition.x][playerPosition.y + 1] == 'C')) points += 50;
			dungeon[playerPosition.x][playerPosition.y + 1] = 'P';
			dungeon[playerPosition.x][playerPosition.y] = ' ';
			playerPosition.y += 1;
			break;
		case ('E'): {
			// To implement
			break;
		}
	}

}