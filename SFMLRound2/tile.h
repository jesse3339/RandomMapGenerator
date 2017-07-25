#pragma once
#include <vector>
#include <SFML/Graphics.hpp>



class Tile
{
public:

	
	int vecPos_X;
	int vecPos_Y;
	sf::RectangleShape rect;
	int rectType; // TODO SET SOMETHING TO DETERMINE TYPE


	void setRectColor();
	void setPosition();
	void setSize();

private:

};