#pragma once
#include "libraries.h"

class Item {

public:
	std::string name;
	int price;
	int winChance;
	std::string description;

};

void PlayerInventory(std::vector<Item>);