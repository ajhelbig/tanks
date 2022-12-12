#pragma once
#include "terrain.hpp"
#include <cmath>

class Tank
{
public:
	int xpos;
	int ypos;
	std::vector<int> &points;

	Tank(std::vector<int> &p);

	void drawTank();

};