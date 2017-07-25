#include "array.h"
#include <random>
#include <vector>
#include <iostream>

#define x 160


//The following two functions create the vector of vectors of integers that are used to map the tiles
//They are randomly filled with 1's and 0's
//TODO Change it so that only the random points that are picked are assigned random integers, not the whole grid

std::vector<int> VectorList::DefineSubVectors(int seed)
{
	srand(seed);
	std::vector<int> subVec;

	for (int i = 0; i < x; i++)
	{

		subVec.push_back(rand() % 2);

	}

	return subVec;

}
std::vector<std::vector<int>> VectorList::DefineVectors()
{

	std::vector<std::vector<int>> vecList;

	for (int i = 0; i < x; i++)
	{
		vecList.push_back(DefineSubVectors(seed+(i*i)));
	}
	return vecList;
}




//Picks random points on the mainVector to use for comparison in the CorrectVect function

void VectorList::PickPoints()
{
	srand(time(NULL)); //sets psuedo-=random seed


	//pick random x points
	for (int i = 0; i < x/4; i++)
	{
		
		pointsX.push_back(rand() % x);
		std::cout << pointsX[i] << ", ";
	}
	std::cout << std::endl;


	//pick random y points
	for (int j = 0; j < x/4; j++)
	{
		
		pointsY.push_back(rand() % x);
		std::cout << pointsY[j] << ", ";
	}
	std::cout << std::endl;

}

//Sets the values of the vector to what they should be

void VectorList::CorrectVect()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			//ONLY USE THE LINE BELOW FOR DEBUGGING!! HURTS COMPILETIME
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
				dist = sqrt(    ((i-pointsX[pX]) * (i - pointsX[pX])) + ((j - pointsY[pX]) * (j - pointsY[pX]))	);
				if (dist < lowestDist) 
				{
					lowestDist = dist;
					mainVector[i][j] = mainVector[pointsX[pX]][pointsY[pX]];
					
				}
			}
		}
	}
}



/*
Following function reads the vector out to the console

Really hurts compile time
*/

void VectorList::ReadVector()
{
	for (int i = 0; i < x; i++)
	{
		std::cout << "{ ";

		for (int j = 0; j < x; j++)
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
