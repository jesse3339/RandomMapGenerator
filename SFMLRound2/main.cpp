#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "DataStruct.h"
#include "MapGenerator.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "MapGen");

	MapGenerator mapGen;
	mapGen.SetUpPrimaryStructure();

	int loopCount;
	std::cout << "Please enter the amount of loops (Preferably less than 7): ";
	std::cin >> loopCount;

	for (int i = 0; i < loopCount; i++)						//TODO Wrap this up inside the function
	{
		mapGen.SetupNextStructure();
		std::cout << "step" << std::endl;
	}

	std::cout << "The total size of the map is: " << mapGen.primaryStructure.size()  << "square tiles" << std::endl;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		window.clear();
		sf::RectangleShape rect;								
		float sizeOfTiles = 2;
		float distanceBtwnTiles = 3;
		rect.setSize(sf::Vector2f(sizeOfTiles, sizeOfTiles));						

		for (int x = 0; x < mapGen.primaryStructure.width(); x++)
		{
			for (int y = 0; y < mapGen.primaryStructure.length(); y++)
			{
				int pointOnGrid = mapGen.primaryStructure.valueAt(x, y);	// gathers value of point to compare the value	

				switch (pointOnGrid)
				{
				case(0):										
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Blue);
					window.draw(rect);
					break;

				case(1):										
					rect.setPosition(sf::Vector2f(x * distanceBtwnTiles, y * distanceBtwnTiles));
					rect.setFillColor(sf::Color::Blue);
					window.draw(rect);
					break;

				case(2):										
					rect.setPosition(sf::Vector2f(x * distanceBtwnTiles, y * distanceBtwnTiles));
					rect.setFillColor(sf::Color::Green);
					window.draw(rect);
					break;

				case(3):										
					rect.setPosition(sf::Vector2f(x * distanceBtwnTiles, y * distanceBtwnTiles));
					rect.setFillColor(sf::Color::Yellow);
					window.draw(rect);
					break;

				case(4):										
					rect.setPosition(sf::Vector2f(x * distanceBtwnTiles, y * distanceBtwnTiles));
					rect.setFillColor(sf::Color::Cyan);
					window.draw(rect);
					break;

				case(9):										
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Red);
					window.draw(rect);
					break;
				default:
					break;
				}
			}
		}
		
	
		
		window.display();
	}
	
	return 0;
}