#pragma once
#include "DataStruct.h"
#include <random>

class MapGenerator {
public:
	void SetUpPrimaryStructure();
	void SetupNextStructure();
	void SetColumnValues(int x);
	void SetRowValues(int y);


	void FillPrimaryStructure();
	std::vector<int> DetermineNeighbors(int x, int y);

	RectangleDataStructure<int> primaryStructure;

private:
	int right;
	int left;
	int above;
	int below;
	RectangleDataStructure<int> secondaryStructure;
	
	
};