#include "MapGenerator.h"
#include <random>
#include <time.h>
#include <iostream>



void MapGenerator::SetUpPrimaryStructure()
{
	primaryStructure.SetStructure(0, 4, 4);

	enum tileType{
		blank, //0
		water, 
		grass, 
		sand, 
		cyan
	};

	std::vector<int> values =   {water, water, water, water,
								 water, grass, sand, water,
								 water, grass, cyan, water,
								 water, water, water, water, };

	primaryStructure.SetAllValues(values);
}

void MapGenerator::SetupNextStructure()
{
	secondaryStructure = primaryStructure;
	setSeed();
	for (int x = 1; x < primaryStructure.width(); x++)
	{
		secondaryStructure.InsertColBefore(x, 9 );
		SetColumnValues((x*2) -1);
	}

	for (int y = 1; y < primaryStructure.length(); y++)
	{
		secondaryStructure.InsertRowBefore(y, 9);
		SetRowValues((y*2) - 1);
	}
	primaryStructure = secondaryStructure;
}

void MapGenerator::SetColumnValues(int x)
{

	for (int y = 0; y < secondaryStructure.length(); y++)
	{
		int left = secondaryStructure.valueAt(x - 1, y);
		int right = secondaryStructure.valueAt(x + 1, y);

		if (left == right){
			secondaryStructure.SetValueAt(x, y, right);
		}
		else{

			int det = randDet() % 2 + 1;
			if (det == 1)
			{
				secondaryStructure.SetValueAt(x, y, (left));
			}
			else
			{
				secondaryStructure.SetValueAt(x, y, (right));
			}

		}
	}
}

void MapGenerator::SetRowValues(int y)
{

	for (int x = 0; x < secondaryStructure.width(); x ++)
	{
		int below = secondaryStructure.valueAt(x, y + 1);
		int above = secondaryStructure.valueAt(x, y -1);
		if (above == below){
			secondaryStructure.SetValueAt(x, y, below);
		}
		else{
			int det = randDet() % 2 + 1;
			if (det == 1)
			{
				secondaryStructure.SetValueAt(x, y, (below));
			}
			else 
			{
				secondaryStructure.SetValueAt(x, y, (above));
			}

		}
	}
}

/////////////////////////////////////////////////////////////////
//Following two functions do not work, nor are they implemented//
/////////////////////////////////////////////////////////////////
#pragma region OLD_CODE
	void MapGenerator::FillPrimaryStructure()
	{
		std::minstd_rand simprand;
		simprand.seed(12);
		for (int x = 0; x < primaryStructure.width(); x++)
		{
			for (int y = 0; y < primaryStructure.length(); y++)
			{
				if (primaryStructure.valueAt(x, y) = 9) //maybe remove?
				{
					std::vector<int> nList = DetermineNeighbors(x, y);
					int decider = (simprand() % 2) + 1;

					int gCount = 0;
					int wCount = 0;
					for (std::vector<int>::iterator iter = nList.begin(); iter != nList.end(); iter++)
					{
						if (*iter = 1)
						{
							gCount++;
						}
						if (*iter = 2)
						{
							wCount++;
						}
					}
					if (gCount > wCount)
					{
						primaryStructure.SetValueAt(x, y, 1);
					}
					if (wCount > gCount)
					{
						primaryStructure.SetValueAt(x, y, 2);
					}
					if (wCount == gCount)
					{
						primaryStructure.SetValueAt(x, y, decider);
					}

				}
			}
		}
	}

	std::vector < int > MapGenerator::DetermineNeighbors(int x, int y)
	{
		std::vector<int> neighborlist;

		if ((x > 0) && (y > 0))
		{
			int nUpLeft = primaryStructure.valueAt(x - 1, y - 1);
			neighborlist.push_back(nUpLeft);
		}

		if (y > 0)
		{
			int nUp = primaryStructure.valueAt(x, y - 1);
			neighborlist.push_back(nUp);
		}

		if ((x < primaryStructure.width() - 1) && (y > 0))
		{
			int nUpRight = primaryStructure.valueAt(x + 1, y - 1);
			neighborlist.push_back(nUpRight);
		}
		if (x > 0)
		{
			int nLeft = primaryStructure.valueAt(x - 1, y);
			neighborlist.push_back(nLeft);
		}
		int nCenter = primaryStructure.valueAt(x, y);
		neighborlist.push_back(nCenter);
		if (x < primaryStructure.width() - 1)
		{
			int nRight = primaryStructure.valueAt(x + 1, y);
			neighborlist.push_back(nRight);
		}

		if ((x > 0) && (y < primaryStructure.length() - 1))
		{
			int nLowLeft = primaryStructure.valueAt(x - 1, y + 1);
			neighborlist.push_back(nLowLeft);
		}

		if (y < primaryStructure.length() - 1)
		{
			int nLow = primaryStructure.valueAt(x, y + 1);
			neighborlist.push_back(nLow);
		}

		if ((x < primaryStructure.width() - 1) && (y < primaryStructure.length() - 1))
		{
			int nLowRight = primaryStructure.valueAt(x + 1, y + 1);
			neighborlist.push_back(nLowRight);
		}

		return neighborlist;
	}
#pragma endregion OLD_CODE