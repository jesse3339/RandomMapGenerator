#include "data.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.h"
#include <random>

void Grid::DefineGridPoints()
{
	srand(time(NULL));

	table = std::vector<std::vector<int>>(80, std::vector<int>(80, 0));
	for (int x = 0; x < 80; x++)
	{
		for (int y = 0; y < 80; y++)
		{
			table[x][y] = rand() % 2;
		}
	}
}

void Grid::DefineTileVec()
{
	for (int X = 0; X < 80; X++)
	{
		for (int Y = 0; Y < 80; Y++)
		{	
			Tile tile;
			tile.vecPos_X = X;
			tile.vecPos_Y = Y;
			tile.setRectColor();
			tile.setPosition();
			tile.setSize();
		}
	}
}

void Grid::PrintGrid()
{

	for (int x = 0; x < 80; x++)
	{
		for (int y = 0; y < 80; y++)
		{
			
			std::cout << "step" << std::endl;
			

// 			if (pointTypeVec[x][y] == Grass)
// 			{
// 				tile.setFillColor(sf::Color::Green);
// 				std::cout << "tile printed" << std::endl;
// 			}
			

		}
	}
}
