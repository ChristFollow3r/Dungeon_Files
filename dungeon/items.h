#pragma once
#include "libraries.h"

/// <summary>
/// The item class
/// </summary>
class Items {

	public:

		std::string itemName;
		std::string itemDescription;
		int itemPrice;

};
/// <summary>
/// Returns a random item
/// </summary>
/// <returns></returns>
Items GetRandomItem();

/// <summary>
/// Gets 5 random items to sell to the player
/// </summary>
/// <param name="money">The amount of money the user has</param>
/// <param name="inventory">The user inventory</param>
void Shop(int& money, std::vector<Items>& inventory);
