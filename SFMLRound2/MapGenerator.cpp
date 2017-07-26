#include "MapGenerator.h"
#include <random>

void MapGenerator::SetUpPrimaryStructure()
{
	primaryStructure.SetStructure(0, 2, 2);

	//set different values for each corner
	primaryStructure.SetValueAt(0, 0, 1);
	primaryStructure.SetValueAt(1, 0, 2);
//	primaryStructure.SetValueAt(2, 0, 2);
	primaryStructure.SetValueAt(0, 1, 4);
	primaryStructure.SetValueAt(1, 1, 3);
//	primaryStructure.SetValueAt(2, 1, 2);
// 	primaryStructure.SetValueAt(0, 2, 2);
// 	primaryStructure.SetValueAt(1, 2, 4);
// 	primaryStructure.SetValueAt(2, 2, 4);
}

void MapGenerator::SetupNextStructure()
{
	secondaryStructure = primaryStructure;

	for (int x = 0; x < primaryStructure.width(); x++)
	{
		if (x > 0) {
			secondaryStructure.InsertColBefore(x, 9 );
		}
	}
	for (int y = 0; y < primaryStructure.length(); y++)
	{
		if (y > 0) {
			secondaryStructure.InsertRowBefore(y, 9);
		}

	}
	primaryStructure = secondaryStructure;
}

void MapGenerator::FillPrimaryStructure()
{
	for (int x = 0; x < primaryStructure.width() -1; x++)
	{
		for (int y = 0; y < primaryStructure.length() -1; y++)
		{
			if (primaryStructure.valueAt(x, y) = 9)
			{
				DetermineNeighbors(x, y);		
				std::minstd_rand simprand;
				int decider = (simprand() % 4);

				if ((right == left) && (above == below) && (left = above))
				{
					primaryStructure.SetValueAt(x, y, left);
				}

				else if ((right != left) && (above == 0 || below == 0))
				{
					if ((decider % 2) == 1)
					{
						primaryStructure.SetValueAt(x, y, right);
					}
					else
					{
						primaryStructure.SetValueAt(x, y, left);
					}
				}

				else if ((above != below) && (right == 0 || left == 0))
				{
					if ((decider % 2) == 1)
					{
						primaryStructure.SetValueAt(x, y, above);
					}
					else
					{
						primaryStructure.SetValueAt(x, y, below);
					}
				}
				else if (right == left)
				{
					primaryStructure.SetValueAt(x, y, left);
				}
				else if (above == below)
				{
					primaryStructure.SetValueAt(x, y, below);
				}


			}
		}
	}
}

void MapGenerator::DetermineNeighbors(int x, int y)
{
	if (x != primaryStructure.width() - 2)
	{
		right = primaryStructure.valueAt(x + 1, y);
	}
	else
	{
		right = NULL;
	}
	
	if (x != 0)
	{
		left = primaryStructure.valueAt(x - 1, y);
	}
	else
	{
		left = NULL;
	}

	if (y != 0)
	{
		above = primaryStructure.valueAt(x, y - 1);
	}
	else
	{
		above = NULL;
	}
	
	if (y != primaryStructure.length() - 2)
	{
		below = primaryStructure.valueAt(x, y + 1);
	}
	else
	{
		left = NULL;
	}
}
