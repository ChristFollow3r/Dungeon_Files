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

void OpenShop(std::vector<Item> avalibleItems, int& money, int& winChance, int& playerHealth, bool& bomb, bool& gamblingCoin) {

	system("cls");
	std::cout << "Welcome to my humble shop :)\nThis is all I can offer you today...\n\n";
	int rItem = 0;

	for (int i = 0; i < 3; i++)
	{
		rItem = rand() % 5; 


		std::cout << "Name: " << avalibleItems[rItem].name << "\n";
		std::cout << "Price: " << avalibleItems[rItem].price << "\n";
		std::cout << "WinChance Increase: " <<  avalibleItems[rItem].winChance << "\n";
		std::cout << "Item Description: " << avalibleItems[rItem].description << "\n\n";
	}

	std::string input; 

	system("pause");
	std::cout << "\nSo... Are you interested in any item? (y) / (n)\n";
	std::cin >> input;
	std::cout << "\n";

	if (input == "n" || input == "N") {
		system("cls");
		std::cout << "Alright then, goodbye!\n";
		system("pause");
		return;
	}
	std::cin.clear();
	std::cin.ignore();

	std::cout << "What's the name of the item you want to buy: \n";
	std::cin >> input; 

	for (int i = 0; i < avalibleItems.size(); i++)
	{
		if (avalibleItems[i].name == input && money >= avalibleItems[i].price) {
			money -= avalibleItems[i].price;
			winChance += avalibleItems[i].winChance;
			system("cls");
			std::cout << "Congratulations! Now you are a proud owner of '" << avalibleItems[i].name << "'.\n";

			if (avalibleItems[i].name == "Potion") playerHealth += 1;
			else if (avalibleItems[i].name == "Bomb") bomb = true;
			else if (avalibleItems[i].name == "Gambling_Coin") gamblingCoin = true;

			system("pause");
			system("cls");
			std::cout << "Good luck out there!\n";
			system("pause");
			break;
		}

		else if (avalibleItems[i].name == input && money < avalibleItems[i].price) {
			std::cout << "You don't have enough money to buy that item...\n";
			system("pause");
			system("cls");
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

void PlayerKillHimSelf(bool& bomb, int& winChance) {
	system("cls");
	if (bomb == false) {
		std::cout << "You don't have a bomb to kill your self. In this real the only way to kill one's self is blowing your self up...\n";
		std::cout << "Regular weapons won't do, so go to a shop if you really want to die, and buy a bomb, and do what you must do.\n";
		std::cout << "Thought keep in mind you can escape this dungeon without killing your self.\n";
		return;
	}
	std::string input;

	std::cout << "Are you sure you want to kill your self: ";
	std::cin >> input;

	if (input == "y" || input == "Y" || input == "yes" || input == "YES" && bomb == true) {
		system("cls");
		std::cout << "Our once proud hero, facing now the challenges of life, decides to give up on it, bringing shame uppon all his lineage...\n";
		system("pause");
		system("cls");
		std::cout << "His last words were...\n";
		system("pause");
		system("cls");
		std::cout << "Surely, one will come after me. One that will clear a path in this dungeon...\n";
		system("pause");
		system("cls");
		std::cout << "One who'll be called...\n";
		system("pause");
		system("cls");
		std::cout << "The Great Hero.\n";
		system("pause");
		system("cls");
		std::cout << "You died.\n";
		system("pause");
		exit(0);
	}

	else {
		std::cout << "Our brave hero holds on to his life a bit more...\n";
		system("cls");
		system("pause");
		std::cout << "Prehaps enough to gain the necessary strength to get out of this dungeon...\n";
		winChance += 2; // Main Character aura lol
		system("pause");
		return;
	}
}

void GamblingCoin(int& money, int& playerHealth, bool& gamblingCoin) {

	int rChannce = rand() % 101;
	if (gamblingCoin == true) {

		system("cls");
		std::cout << "You flip a magical coin...\n";
		system("pause");
		system("cls");
		std::cout << "It rises up in the air...\n";
		system("pause");
		system("cls");
		std::cout << "You stare at it...\n";
		system("pause");
		system("cls");
		std::cout << "And you think yo yourself...\n";
		system("pause");
		system("cls");
		std::cout << "What's that coing made off?\n";
		system("pause");
		system("cls");
		std::cout << "The coin starts to fall...\n";
		system("pause");
		system("cls");
		std::cout << "It's about to reach your hand again...\n";
		system("pause");
		system("cls");


		if (rChannce >= 50) {
			std::cout << "It's heads!\n";
			system("pause");
			system("cls");
			std::cout << "The coin emits a feble light...\n";
			system("pause");
			system("cls");
			std::cout << "You you've gained 700 coins!\n";
			system("pause");
			system("cls");
			gamblingCoin = false;
			money += 700;
		}

		else {
			std::cout << "It's tails!\n";
			system("pause");
			system("cls");
			std::cout << "The coin starts to shake violently...\n";
			system("pause");
			system("cls");
			std::cout << "It starts to make a hineous sound...\n";
			system("pause");
			system("cls");
			std::cout << "...";
			system("pause");
			std::cout << "The coin explodes!\n";
			system("pause");
			system("cls");
			std::cout << "Your life has been greatly hindered...\n";
			system("pause");
			system("cls");
			
			playerHealth -= 2;

			if (playerHealth <= 0) {
				std::cout << "Gambling has yet taken another life...\n";
				system("pause");
				system("cls");
				std::cout << "You died.\n";
				system("pause");
				exit(0);
			}
		}
	}

	else {
		system("cls");
		std::cout << "You dont own a Gambling coin...";
		system("pause");
		return;
	}
}

void PlayerMovement(std::vector<std::vector<char>>& dungeon, Position& playerPosition, int& money, int& winChance, int& playerHealth, std::vector<Item> avalibleItems, bool& bomb, bool& gamblingCoin) {

	std::string input;
	char direction;

	std::cout << "Up (W), Down (S), Left (A), Right (D), Exit (E): ";
	std::cin >> input;

	if (input == "w") input = "W";
	else if (input == "s") input = "S";
	else if (input == "a") input = "A";
	else if (input == "d") input = "D";
	else if (input == "e") input = "E";
	else if (input == "k") input = "K";
	else if (input == "g") input = "G";

	direction = input[0];

	switch (direction) {

	case ('W'):

		if (dungeon[playerPosition.x - 1][playerPosition.y] == '#') break;

		else if ((dungeon[playerPosition.x - 1][playerPosition.y] == 'C')) AddPoints(money, winChance);
		else if (dungeon[playerPosition.x - 1][playerPosition.y] == 'O') EscapeDungeon(money);
		else if (dungeon[playerPosition.x - 1][playerPosition.y] == 'S') {
			OpenShop(avalibleItems, money, winChance, playerHealth, bomb, gamblingCoin);
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
			OpenShop(avalibleItems, money, winChance, playerHealth, bomb, gamblingCoin);
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
			OpenShop(avalibleItems, money, winChance, playerHealth, bomb, gamblingCoin);
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
			OpenShop(avalibleItems, money, winChance, playerHealth, bomb, gamblingCoin);
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

	case ('K'): 
		PlayerKillHimSelf(bomb, winChance);
		break;

	case ('G'):
		GamblingCoin(money, playerHealth, gamblingCoin);
		break;

	default:

		break;
	}

}