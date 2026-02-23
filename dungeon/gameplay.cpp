#include "libraries.h"
#include "gameplay.h"

// Martí, amb aquestes dos funcions he apress la seva inportància.
// Habia escrit aquestes dos funcions 8 vegades en total.
// I penso. Pero retrassat fes-te una funció. LOL. Un positiu no?

// Segurament es poden arreglar mmoltes mes cosses però amb això estic content :)

void AddPoints(int& points, int& winChance) {
	points += rand() % 100;
	winChance += rand() % 100;
}

void EscapeDungeon(int& points) {
	system("cls");
	char input;
	std::cout << "Do you want to escape the dungeon? (y / n)\n";
	std::cin >> input;
	if (input == 'y' && points >= 800) {
		system("cls");
		std::cout << "Congratulations... You managed to escape the dungeon!\n";
		system("pause");
		std::exit(0); // Això de exit li he preguntat a la IA perquè no tenia ni idea de com fer-ho (es tot lo de IA que n'hi ha en el programa fins ara :)
	}

	else {
		system("cls");
		std::cout << "You dont have enought money to buy your way out!\nCome back with 800 coins...\nIf you manage to find your way back lol.\n";
		system("pause");
	}
}

void Enemy(int winChance, int& money, int& playerHealth) {

	system("cls");
	int eAttack = rand() % 100;

	std::cout << "The skeleton attacks you...\n";
	system("pause");
	if (winChance < eAttack) {
		std::cout << "You won this combat!\n";
		system("pause");
		money += rand() % 50;
		return;
	}
	else {
		playerHealth -= 1;
		system("cls");
		if (playerHealth == 0) {
			std::cout << "You died :( Rest in piece brave soldier...\n";
			system("pause");
			exit(0);
		}
		else {
			std::cout << "You took a massive blow from the skeleton, but the dude died in the process.\n";
			system("pause");
			return;
		}
	}

}

void FindShop(std::vector<std::vector<char>>& dungeon) {

	int max = dungeon.size() * dungeon.size();

	for (int i = 0; i < dungeon.size(); i++) {
		for (int j = 0; j < dungeon.size(); j++)
		{
			if (dungeon[i][j] != 'S') max--;
		}
	}

	if (max == 0) dungeon[rand() % dungeon.size()][rand() % dungeon.size()] = 'S';

	// Et deixo aqui un cadaver d'un tros de codi que pensava que era genius moment pero que feia que sortisin pila de S

	//for (int i = 0; i < dungeon.size(); i++) {
	//	auto it = std::find(dungeon[i].begin(), dungeon[i].end(), 'S');
	//	if (it == dungeon[i].end() && i == dungeon.size() - 1) {
	//		dungeon[rand() % dungeon.size()][rand() % dungeon.size()] = 'S';
	//		break;
	//	}
	//}
}

void PlayerMovement(std::vector<std::vector<char>>& dungeon, Position& playerPosition, int& money, int& winChance, int& playerHealth) {

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

	case ('W'):

		if (dungeon[playerPosition.x - 1][playerPosition.y] == '#') break;

		else if ((dungeon[playerPosition.x - 1][playerPosition.y] == 'C')) AddPoints(money, winChance);
		else if (dungeon[playerPosition.x - 1][playerPosition.y] == 'S') EscapeDungeon(money);
		else if (dungeon[playerPosition.x - 1][playerPosition.y] == 'E') Enemy(winChance, money, playerHealth);
		dungeon[playerPosition.x - 1][playerPosition.y] = 'P';
		dungeon[playerPosition.x][playerPosition.y] = ' ';
		FindShop(dungeon);
		playerPosition.x -= 1;
		break;

	case ('S'):
		if (dungeon[playerPosition.x + 1][playerPosition.y] == '#') break;
		else if ((dungeon[playerPosition.x + 1][playerPosition.y] == 'C')) AddPoints(money, winChance);
		else if (dungeon[playerPosition.x + 1][playerPosition.y] == 'S') EscapeDungeon(money);
		else if (dungeon[playerPosition.x + 1][playerPosition.y] == 'E') Enemy(winChance, money, playerHealth);

		dungeon[playerPosition.x + 1][playerPosition.y] = 'P';
		dungeon[playerPosition.x][playerPosition.y] = ' ';
		FindShop(dungeon);
		playerPosition.x += 1;
		break;

	case ('A'):
		if (dungeon[playerPosition.x][playerPosition.y - 1] == '#') break;
		else if ((dungeon[playerPosition.x][playerPosition.y - 1] == 'C')) AddPoints(money, winChance);
		else if (dungeon[playerPosition.x][playerPosition.y - 1] == 'S') EscapeDungeon(money);
		else if (dungeon[playerPosition.x][playerPosition.y - 1] == 'E') Enemy(winChance, money, playerHealth);

		dungeon[playerPosition.x][playerPosition.y - 1] = 'P';
		dungeon[playerPosition.x][playerPosition.y] = ' ';
		FindShop(dungeon);
		playerPosition.y -= 1;
		break;

	case ('D'):
		if (dungeon[playerPosition.x][playerPosition.y + 1] == '#') break;
		else if ((dungeon[playerPosition.x][playerPosition.y + 1] == 'C')) AddPoints(money, winChance);
		else if (dungeon[playerPosition.x][playerPosition.y + 1] == 'S') EscapeDungeon(money);
		else if (dungeon[playerPosition.x][playerPosition.y + 1] == 'E') Enemy(winChance, money, playerHealth);

		dungeon[playerPosition.x][playerPosition.y + 1] = 'P';
		dungeon[playerPosition.x][playerPosition.y] = ' ';
		FindShop(dungeon);
		playerPosition.y += 1;
		break;
	case ('E'): {
		SaveAndExitGame(dungeon);
		exit(0);
	}
	}

}