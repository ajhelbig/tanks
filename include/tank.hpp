#pragma once
#include "terrain.hpp"
#include "projectile.hpp"
#include <bits/stdc++.h>

class Tank
{
public:
	int xpos;
	int ypos;
	int tankLength;
	int tankHeight;
	int blockSize;

	Vector2 turretTip;
	Vector2 turretBase;

	std::vector<int> &points;
	std::vector<Projectile> shells;

	Tank(std::vector<int> &p, int blockSize);

	void updateTank();
	void updateTurret();
	void drawTank();
	void fire();

};