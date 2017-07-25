#pragma once
#include <vector>
#include <SFML/Graphics.hpp>


class Grid
{

public:

	std::vector<std::vector<int>> table;


	void DefineGridPoints();
	void DefineTileVec();
	void PrintGrid();

protected:

private:

};