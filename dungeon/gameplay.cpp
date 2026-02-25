#include "libraries.h"
#include "gameplay.h"

// Martí, amb aquestes dos funcions he apress la seva inportància.
// Habia escrit aquestes dos funcions 8 vegades en total.
// I penso. Pero retrassat fes-te una funció. LOL. Un positiu no?

// Segurament es poden arreglar mmoltes mes cosses però amb això estic content :)

void AddPoints(int& points, int& winChance) {
	points += rand() % 100;
	winChance += rand() % 10;
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

	std::cout << "The skeleton attacks you... ";
	system("pause");
	if (winChance > eAttack) {
		std::cout << "You won this combat!\n";
		system("pause");
		money += rand() % 50;
		return;
	}
	else {
		playerHealth -= 1;
		system("cls");
		if (playerHealth <= 0) {
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

void OpenShop(std::vector<Item> avalibleItems, int& money, int& winChance, int& playerHealth) {

	system("cls");
	std::cout << "Welcome to my humble shop :)\nThis is all I can offer you today...\n\n";
	int rItem = 0;

	for (int i = 0; i < 3; i++)
	{
		rItem = rand() % 5; // This shit doesnt work properly
		// The problem must be in avalibleItems

		std::cout << "Name: " << avalibleItems[rItem].name << "\n";
		std::cout << "Price: " << avalibleItems[rItem].price << "\n";
		std::cout << "WinChance Increase: " <<  avalibleItems[rItem].winChance << "\n";
		std::cout << "Item Description: " << avalibleItems[rItem].description << "\n\n";
	}

	std::string input; // This shit doesnt work 

	system("pause");
	std::cout << "\nSo... Are you interested in any item?\n";
	std::cout << "What's the name of the item you want to buy: \n";
	std::cin >> input; 

	for (int i = 0; i < avalibleItems.size(); i++)
	{
		if (avalibleItems[i].name == input && money >= avalibleItems[i].price) {
			money -= avalibleItems[i].price;
			winChance += avalibleItems[i].winChance;
			std::cout << "\nCongratulations! Now you are a proud owner of '" << avalibleItems[i].name << "'.\n";

			if (avalibleItems[i].name == "Potion") playerHealth += 1;

			system("pause");
			std::cout << "\nGood luck out there!\n";
			system("pause");
			break;
		}

		else if (avalibleItems[i].name == input && money < avalibleItems[i].price) {
			std::cout << "You don't have enough money to buy that item...\n";
			system("pause");
			std::cout << "Please come back whenever you have enough money to buy it. I also do have a family to feed.\n";
			system("pause");
			break;
		}

		else if (avalibleItems[i].name != input && i == avalibleItems.size() - 1) {
			std::cout << "That item doesn't exist...\n";
			system("pause");
			break;
		}
	}
}

void FindShop(std::vector<std::vector<char>>& dungeon) { // Este nombre de funcion ya no refleja lo que hace ahora pero soy demasiado 
														// Vago como para cambiar el nombre ahora
	int max = dungeon.size() * dungeon.size();

	for (int i = 0; i < dungeon.size(); i++) {
		for (int j = 0; j < dungeon.size(); j++)
		{
			if (dungeon[i][j] != 'O') max--;
		}
	}

	if (max == 0) dungeon[rand() % dungeon.size()][rand() % dungeon.size()] = 'O'; 

	// Et deixo aqui un cadaver d'un tros de codi que pensava que era genius moment pero que feia que sortisin pila de S

	//for (int i = 0; i < dungeon.size(); i++) {
	//	auto it = std::find(dungeon[i].begin(), dungeon[i].end(), 'S');
	//	if (it == dungeon[i].end() && i == dungeon.size() - 1) {
	//		dungeon[rand() % dungeon.size()][rand() % dungeon.size()] = 'S';
	//		break;
	//	}
	//}
}

void PlayerMovement(std::vector<std::vector<char>>& dungeon, Position& playerPosition, int& money, int& winChance, int& playerHealth, std::vector<Item> avalibleItems) {

	std::string input;
	char direction;

	std::cout << "Up (W), Down (S), Left (A), Right (D), Exit (E): ";
	std::cin >> input;

	if (input == "w") input = "W";
	else if (input == "s") input = "S";
	else if (input == "a") input = "A";
	else if (input == "d") input = "D";
	else if (input == "e") input = "E";

	direction = input[0];

	switch (direction) {

	case ('W'):

		if (dungeon[playerPosition.x - 1][playerPosition.y] == '#') break;

		else if ((dungeon[playerPosition.x - 1][playerPosition.y] == 'C')) AddPoints(money, winChance);
		else if (dungeon[playerPosition.x - 1][playerPosition.y] == 'O') EscapeDungeon(money);
		else if (dungeon[playerPosition.x - 1][playerPosition.y] == 'S') {
			OpenShop(avalibleItems, money, winChance, playerHealth);
			dungeon[playerPosition.x - 1][playerPosition.y] = 'S'; // Change here
			break;
		}
		else if (dungeon[playerPosition.x - 1][playerPosition.y] == 'E') Enemy(winChance, money, playerHealth);
		dungeon[playerPosition.x - 1][playerPosition.y] = 'P';
		dungeon[playerPosition.x][playerPosition.y] = ' ';
		FindShop(dungeon);
		playerPosition.x -= 1;
		break;

	case ('S'):
		if (dungeon[playerPosition.x + 1][playerPosition.y] == '#') break;
		else if ((dungeon[playerPosition.x + 1][playerPosition.y] == 'C')) AddPoints(money, winChance);
		else if (dungeon[playerPosition.x + 1][playerPosition.y] == 'O') EscapeDungeon(money);
		else if (dungeon[playerPosition.x + 1][playerPosition.y] == 'S') {
			OpenShop(avalibleItems, money, winChance, playerHealth);
			dungeon[playerPosition.x + 1][playerPosition.y] = 'S'; // Change here
			break;
		}
		else if (dungeon[playerPosition.x + 1][playerPosition.y] == 'E') Enemy(winChance, money, playerHealth);

		dungeon[playerPosition.x + 1][playerPosition.y] = 'P';
		dungeon[playerPosition.x][playerPosition.y] = ' ';
		FindShop(dungeon);
		playerPosition.x += 1;
		break;

	case ('A'):
		if (dungeon[playerPosition.x][playerPosition.y - 1] == '#') break;
		else if ((dungeon[playerPosition.x][playerPosition.y - 1] == 'C')) AddPoints(money, winChance);
		else if (dungeon[playerPosition.x][playerPosition.y - 1] == 'O') EscapeDungeon(money);
		else if (dungeon[playerPosition.x][playerPosition.y - 1] == 'S') {
			OpenShop(avalibleItems, money, winChance, playerHealth);
			dungeon[playerPosition.x][playerPosition.y - 1] = 'S'; // Change here
			break;
		}
		else if (dungeon[playerPosition.x][playerPosition.y - 1] == 'E') Enemy(winChance, money, playerHealth);

		dungeon[playerPosition.x][playerPosition.y - 1] = 'P';
		dungeon[playerPosition.x][playerPosition.y] = ' ';
		FindShop(dungeon);
		playerPosition.y -= 1;
		break;

	case ('D'):
		if (dungeon[playerPosition.x][playerPosition.y + 1] == '#') break;
		else if ((dungeon[playerPosition.x][playerPosition.y + 1] == 'C')) AddPoints(money, winChance);
		else if ((dungeon[playerPosition.x][playerPosition.y + 1] == 'O')) EscapeDungeon(money);
		else if (dungeon[playerPosition.x][playerPosition.y + 1] == 'S') {
			OpenShop(avalibleItems, money, winChance, playerHealth);
			dungeon[playerPosition.x][playerPosition.y + 1] = 'S'; // Change here
			break;
		}
		else if (dungeon[playerPosition.x][playerPosition.y + 1] == 'E') Enemy(winChance, money, playerHealth);

		dungeon[playerPosition.x][playerPosition.y + 1] = 'P';
		dungeon[playerPosition.x][playerPosition.y] = ' ';
		FindShop(dungeon);
		playerPosition.y += 1;
		break;

	case ('E'): 
		SaveAndExitGame(dungeon);
		exit(0);

	case ('1'): 

		// To do
		break;

	default:
		break;
	}

}