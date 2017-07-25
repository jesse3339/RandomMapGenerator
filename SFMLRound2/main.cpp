#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "data.h"
#include "tile.h"
#include "array.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "MapGen"); //creates window



	VectorList pointGrid; //create vector list

	pointGrid.DefineSubVectors(23423);							//seed to define random ints
	pointGrid.DefineVectors();									//puts subvectors into main vector
	pointGrid.PickPoints();										//picks random points
	std::cout << "Beginning map creation" << std::endl;			//to tell me when map creation begins
	pointGrid.CorrectVect();									//fixes the map to have points related to points around them

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		/*window.clear();*/
		//THIS IS WHERE WE DRAW THE MAP
		sf::RectangleShape rect;								// initialize base rectangle
		rect.setSize(sf::Vector2f(4, 4));						// size of the rectangle

		for (int x = 0; x < 160; x++)
		{
			for (int y = 0; y < 160; y++)
			{
				int pointOnGrid = pointGrid.mainVector[x][y];	// gathers value of point to compare the value	

				switch (pointOnGrid)
				{
				case(0):										// if = 0 set it green
						
					rect.setPosition(sf::Vector2f(x * 5, y * 5));
					rect.setFillColor(sf::Color::Green);
					window.draw(rect);
					
					break;
				case(1):										//if = 1 set it to blue
					rect.setPosition(sf::Vector2f(x * 5, y * 5));
					rect.setFillColor(sf::Color::Blue);
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