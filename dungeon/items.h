#pragma once
#include "libraries.h"

class Items {

	public:

		std::string itemName;
		std::string itemDescription;
		int itemPrice;

};

void Shop(int& money, std::vector<Items>);
