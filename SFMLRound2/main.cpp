#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "DataStruct.h"
#include "MapGenerator.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "MapGen");



	MapGenerator mapGen;
	mapGen.SetUpPrimaryStructure();
	for (int i = 0; i < 2; i++)
	{
		mapGen.SetupNextStructure();
 		//mapGen.FillPrimaryStructure();
		std::cout << "step" << std::endl;
	}
	for (std::vector<int>::iterator it = mapGen.primaryStructure.begin(); it != mapGen.primaryStructure.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	

	/*std::cout << mapGen.primaryStructure.valueAt(2, 2) << std::endl;*/
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		window.clear();
		//THIS IS WHERE WE DRAW THE MAP
		sf::RectangleShape rect;								// initialize base rectangle
		
		rect.setSize(sf::Vector2f(9, 9));						// size of the rectangle

		for (int x = 0; x < mapGen.primaryStructure.len(); x++)
		{
			for (int y = 0; y < mapGen.primaryStructure.len(); y++)
			{
				int pointOnGrid = mapGen.primaryStructure.valueAt(x, y);	// gathers value of point to compare the value	

				switch (pointOnGrid)
				{
				case(0):										//if = 1 set it to blue
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Blue);
					window.draw(rect);
					break;

				case(1):										//if = 1 set it to blue
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Green);
					window.draw(rect);
					break;

				case(2):										//if = 2 set it to red
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Blue);
					window.draw(rect);
					break;

				case(3):										//if = 2 set it to red
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Blue);
					window.draw(rect);
					break;

				case(4):										//if = 2 set it to red
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Green);
					window.draw(rect);
					break;

				case(9):										//if = 2 set it to red
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