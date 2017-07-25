#pragma once
#include <random>
#include <time.h>


class VectorList 
{
public:

	const int length = 160;

	std::vector<int> pointsX;
	std::vector<int> pointsY;
	std::vector<  std::vector< int >  > mainVector = DefineVectors();
	std::vector<int> DefineSubVectors();
	std::vector<  std::vector< int >  > DefineVectors();
	void PickPoints();
	void CorrectVect();
	void PrintVector();
};
