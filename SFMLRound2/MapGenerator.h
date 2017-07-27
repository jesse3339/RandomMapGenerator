#pragma once
#include "DataStruct.h"
#include <random>
#include <time.h>
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
	std::minstd_rand randDet;
	void setSeed() {randDet.seed(time(NULL));};
	RectangleDataStructure<int> secondaryStructure;
	
	
};