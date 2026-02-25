#pragma once
#include "libraries.h"
#include "inventory.h"

/// <summary>
/// It's a vector 2
/// </summary>
struct Position {
	int x;
	int y;
};
/// <summary>
/// Adds points (currency) and adds to the winChance variable
/// </summary>
/// <param name="points">The amount of money the player has</param>
/// <param name="winChance">The chances the player has to win a combat</param>
void AddPoints(int& points, int& winChance);
/// <summary>
/// Allows the player to escape the dungeon without fighting
/// </summary>
/// <param name="points">The amount of money the player has</param>
void EscapeDungeon(int& points);
/// <summary>
/// Randomly places a 'P' inside the dungeon if the player exits the shop
/// </summary>
/// <param name="dungeon">The 2D grid where the player plays</param>
void FindExit(std::vector<std::vector<char>>& dungeon);
/// <summary>
/// Enters a simple text fight
/// </summary>
/// <param name="winChance">The chances the player has to win a fight</param>
/// <param name="money">The amount of money the player has</param>
/// <param name="playerHealth">The player health</param>
void Enemy(int winChance, int& money, int& playerHealth);
/// <summary>
/// Move the player inside the dungeon and other stuff (like getting money from chests)
/// </summary>
/// <param name="dungeon">The 2D grid</param>
/// <param name="playerPosition">The player position</param>
/// <param name="points">The amount of points the player has</param>
void PlayerMovement(std::vector<std::vector<char>>& dungeon, Position &playerPosition, int& money, int& winChance, int& playerHealth, std::vector<Item> avalibleItems, bool& bomb, bool& gamblingCoin);
/// <summary>
/// Starts a shopping interaction
/// </summary>
/// <param name="avalibleItems">The items avalible in the shop</param>
/// <param name="money">The player amount of money</param
/// <param name="winChance">The chance amount the player has to win a combat</param>
/// <param name="playerHealth">The player health</param>
void OpenShop(std::vector<Item> avalibleItems, int& money, int& winChance, int& playerHealth, bool& bomb, bool& gamblingCoin);
/// <summary>
/// Allows the player to kill himself if he so desires
/// </summary>
/// <param name="bomb">Allows the player to kill himself</param>
/// <param name="winChance">The chance the player has to win a combat</param>
void PlayerKillHimSelf(bool& bomb, int& winChance);
void GamblingCoin(int& money, int& playerHealth, bool& gamblingCoin);