#pragma once
#include "DataStruct.h"

class MapGenerator {
public:
	void SetUpPrimaryStructure();
	void SetupNextStructure();
	void FillPrimaryStructure();
	void DetermineNeighbors(int x, int y);

	RectangleDataStructure<int> primaryStructure;

private:
	int right;
	int left;
	int above;
	int below;
	RectangleDataStructure<int> secondaryStructure;

};