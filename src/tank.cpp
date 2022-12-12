#include "tank.hpp"

void Tank::drawTank()
{
	//tank body
	int tankLenght = 20;
	int tankHeight = 10;

	DrawRectangle(this->xpos, this->ypos, tankLenght, tankHeight, DARKGREEN);
	DrawCircle(this->xpos + tankLenght / 2, this->ypos, tankLenght / 4, DARKGREEN);

	//tank turret
	float mouseX = GetMouseX();
	float mouseY = GetMouseY();

	float turretBaseX = this->xpos + tankLenght /2;
	float turretBaseY = this->ypos - tankLenght / 8;

	float bigHyp = std::sqrt( 
		(mouseX - turretBaseX) * (mouseX - turretBaseX) +
		(mouseY - turretBaseY) * (mouseY - turretBaseY) );
	float turretY = ( ( tankLenght * (mouseY - turretBaseY)) / bigHyp );
	float turretX = std::sqrt( tankLenght * tankLenght - (turretY * turretY) );

	float turretTipX = turretBaseX + turretX;
	float turretTipY = turretBaseY + turretY;

	Vector2 turretBase = {turretBaseX, turretBaseY};

	Vector2 turretTip = {turretTipX, turretTipY};

	DrawLineEx(turretBase, turretTip, 2.0, DARKGREEN);
}

Tank::Tank(std::vector<int> &p):
points{p}
{

	this->xpos = 20;
	this->ypos = this->points.at(0) - 10;

}
