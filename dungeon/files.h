#pragma once
#include "libraries.h"
#include "inventory.h" // No se si possar aquests headers al libraries.h, perquè potser tinc problemes the llibreries circulars.
// No se ben bé com funciona això de les llibreries circulars.

/// <summary>
/// This function allows the user to chose between openning a txt to have a custom dungeon or use the program function to make a dungeon
/// </summary>
/// <returns>2D vector (The dungeon grid)</returns>
std::vector<std::vector<char>> CreateOrNotDungeonWithFile();
/// <summary>
/// Get's items from items.txt
/// </summary>
/// <param name="">The avalible items in the shop</param>
void GetItemsFromFile(std::vector<Item>);
/// <summary>
/// Save's the game in a binary file and exists the game.
/// </summary>
/// <param name="dungeon">The dungeon where the player plays</param>
void SaveAndExitGame(std::vector<std::vector<char>>& dungeon);