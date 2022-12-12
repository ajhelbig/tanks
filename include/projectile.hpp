#pragma once
#include "terrain.hpp"

class Projectile
{
public:

	Vector2 pos;
	float xvelo;
	float yvelo;
	float yaccel;
	int blockSize;
	std::vector<int> &points;

	Projectile(Vector2 pos, float xvelo, float yvelo, 
		std::vector<int> &p, int blockSize);

	void drawShell();
	void updateShell();
	void terminate();
};