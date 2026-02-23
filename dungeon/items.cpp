#include "items.h"

Items GetRandomItem() {


	Items legendarySword;
	Items ironSword;
	Items torch;
	Items bomb;
	Items potion;
	Items tpPotion;
	Items shield;

	Items items[8]{legendarySword, ironSword, torch, bomb, potion, tpPotion, shield};
	int rItem = rand() % 8;

	legendarySword.itemName = "Excalibur";
	legendarySword.itemDescription = "The most powerfull of all the Legendary Swords. Only a warrior with a pure heart is able to weild it.";
	legendarySword.itemPrice = 12500;

	ironSword.itemName = "Iron Sword";
	ironSword.itemDescription = "A trust worthy metal sword. It's not of Legendary status, but with proper weilding it's still able to chop heads off";
	ironSword.itemPrice = 450;

	torch.itemName = "Torch";
	torch.itemDescription = "A regular torch. Use it to make enemies stop spawning";
	torch.itemPrice = 50;

	bomb.itemName = "Bomb";
	bomb.itemDescription = "Use this to open a hole in a wall";
	bomb.itemPrice = 500;

	potion.itemName = "Health Potion";
	potion.itemDescription = "Use this to heal your self";
	potion.itemPrice = 300;

	tpPotion.itemName = "Teleport Potion";
	tpPotion.itemDescription = "Use this to go back to the spawn point";
	tpPotion.itemPrice = 2000;

	shield.itemName = "Shield";
	shield.itemDescription = "Use this to block enemy attacks";
	shield.itemPrice = 700;

	return items[rItem];
}

void Shop(int& money, std::vector<Items>& inventory) {

	std::string input;
	int choice;
	std::vector<Items> avalibeItems;
	
	for (int i = 0; i < 5; i++) avalibeItems.push_back(GetRandomItem());

	std::cout << "Welcome to my humble shop. Are you looking to buy anything?\n";
	std::cout << "This are the items I can currently offer you\n";

	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 <<": " << avalibeItems[i].itemName << "\n";
	}

	std::cout << "So what are you interested in? (1,2,3,4,5 or exit)\n";

	while (input != "exit") {

		std::cin >> input;
		choice = stoi(input);

		switch (choice) {
		case 1:
			if (money >= avalibeItems[choice - 1].itemPrice) {
				inventory.push_back(avalibeItems[choice - 1]);
				// Delte item TO DO
			}
			else std::cout << "You don't have enough money to buy this!\n";
			break;

		case 2:
			if (money >= avalibeItems[choice - 1].itemPrice) {
				inventory.push_back(avalibeItems[choice - 1]);
				// Delte item TO DO
			}
			else std::cout << "You don't have enough money to buy this!\n";
			break;

		case 3:
			if (money >= avalibeItems[choice - 1].itemPrice) {
				inventory.push_back(avalibeItems[choice - 1]);
				// Delte item TO DO
			}
			else std::cout << "You don't have enough money to buy this!\n";
			break;

		case 4:
			if (money >= avalibeItems[choice - 1].itemPrice) {
				inventory.push_back(avalibeItems[choice - 1]);
				// Delte item TO DO
			}
			else std::cout << "You don't have enough money to buy this!\n";
			break;

		case 5:

			if (money >= avalibeItems[choice - 1].itemPrice) {
				inventory.push_back(avalibeItems[choice - 1]);
				// Delte item TO DO
			}
			else std::cout << "You don't have enough money to buy this!\n";
			break;

		}

	}
}

