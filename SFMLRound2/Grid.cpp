#include "Grid.h"
#include <random>
#include <vector>
#include <iostream>




//The following two functions create the vector of vectors of integers that are used to map the tiles
//They are randomly filled with 1's and 0's
//TODO Change it so that only the random points that are picked are assigned random integers, not the whole grid

std::vector<int> VectorList::DefineSubVectors()
{
	std::minstd_rand simple_rand;
	simple_rand.seed();
	std::vector<int> subVec;

	for (int i = 0; i < length; i++)
	{

		subVec.push_back(simple_rand() % 6);

	}

	return subVec;

}
std::vector<std::vector<int>> VectorList::DefineVectors()
{

	std::vector<std::vector<int>> vecList;

	for (int i = 0; i < length; i++)
	{
		vecList.push_back(DefineSubVectors());
	}
	return vecList;
}




//Picks random points on the mainVector to use for comparison in the CorrectVect function

void VectorList::PickPoints()
{
	srand(time(NULL)); //sets pseudo-random seed


	//pick random x points
	for (int i = 0; i < length/8; i++)
	{
		
		pointsX.push_back(rand() % length);
		std::cout << pointsX[i] << ", ";
	}
	std::cout << std::endl;


	//pick random y points
	for (int j = 0; j < length/8; j++)
	{
		
		pointsY.push_back(rand() % length);
		std::cout << pointsY[j] << ", ";
	}
	std::cout << std::endl;

}

//Sets the values of the vector to what they should be

void VectorList::CorrectVect()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			//ONLY USE THE LINE BELOW FOR DEBUGGING!!
			//std::cout << "on coordinate: (" << i << "," << j << ")" << std::endl;



			//////////////////////////////////////////////////////////////////////////
			// Compares each point in the mainVector to each set of random points ////
			//                                                                    ////
			// Sets the value of the point it is testing the distance from to the ////
			// value of the closest random point pair                             ////
			//////////////////////////////////////////////////////////////////////////

			float dist = 1000; //distance value to compare to lowest dist
			float lowestDist = 999; //^^^

			for (int pX = 0; pX < pointsX.size(); pX++)
			{
				if (j != pointsX[pX] && i != pointsY[pX])
				{

					dist = sqrt(((i - pointsX[pX]) * (i - pointsX[pX])) + ((j - pointsY[pX]) * (j - pointsY[pX])));
					if (dist < lowestDist)
					{
						lowestDist = dist;
						mainVector[i][j] = mainVector[pointsX[pX]][pointsY[pX]];
					}
				}
			}
		}
	}


	for (int pX = 0; pX < pointsX.size(); pX++)
	{
		mainVector[pointsY[pX]][pointsX[pX]] = 9;
	}
}




/*
Following function reads the vector out to the console
*/

void VectorList::PrintVector()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "{ ";

		for (int j = 0; j < length; j++)
		{
			if (VectorList::mainVector[i][j] < 0) 
			{
				std::cout << VectorList::mainVector[i][j] << "    ";
			}
			else
			{
				std::cout << VectorList::mainVector[i][j] << "     ";
			}
		}
		std::cout << "}" << std::endl;
	}
}
