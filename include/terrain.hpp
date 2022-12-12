#pragma once
#include <vector>
#include <iostream>
#include <random>
#include "raylib.h"
#include <ctime>
#include <cmath>

class Terrain
{
public:
	int windowWidth;
	int windowHeight;
	int blockSize;
	int slope;
	int smooth;
	std::vector<int> points;

	Terrain(const int windowWidth, const int windowHeight, int blockSize, int slope, int smooth);

	void generateBlocks();
	void smoothPoints();
	void generatePoints();
	void drawTerrain();

};