#pragma once
#include "DataStruct.h"

class MapGenerator {
public:
	void SetUpPrimaryStructure();
	void SetupNextStructure();
	void FillPrimaryStructure();
	void DetermineNeighbors(int x, int y);

	SquareDataStructure<int> primaryStructure;
private:
	int right;
	int left;
	int above;
	int below;
	SquareDataStructure<int> secondaryStructure;
	int max_neighbors = 4;
};