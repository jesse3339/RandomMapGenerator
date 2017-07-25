#include "tile.h"
#include <SFML/Graphics.hpp>

void Tile::setRectColor()
{
	enum pointTypes { Grass, Water };
	switch (rectType)
	{
		case (Grass):
			rect.setFillColor(sf::Color::Green);

			//ADD MORE CASES
	}

}

void Tile::setPosition()
{
	rect.setPosition(sf::Vector2f(vecPos_X * 10, vecPos_Y * 10));
}

void Tile::setSize()
{
	rect.setSize(sf::Vector2f(10, 10));
}
