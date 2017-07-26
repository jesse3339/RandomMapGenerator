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
	for (int i = 0; i < 5; i++)						//Wrap this up inside the function
	{
		mapGen.SetupNextStructure();
		std::cout << "step" << std::endl;
	}


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
		
		rect.setSize(sf::Vector2f(9, 9));						

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
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Blue);
					window.draw(rect);
					break;

				case(2):										
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Green);
					window.draw(rect);
					break;

				case(3):										
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Blue);
					window.draw(rect);
					break;

				case(4):										
					rect.setPosition(sf::Vector2f(x * 10, y * 10));
					rect.setFillColor(sf::Color::Green);
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