#pragma once
#include <random>
#include <time.h>


class VectorList 
{
public:

	int seed = time(NULL);
	std::vector<int> pointsX;
	std::vector<int> pointsY;
	std::vector<int> DefineSubVectors(int seed);
	std::vector<  std::vector< int >  > DefineVectors();
	std::vector<  std::vector< int >  > mainVector = DefineVectors();
	void PickPoints();
	void CorrectVect();
	void ReadVector();
};
