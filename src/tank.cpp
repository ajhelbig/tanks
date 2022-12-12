#include "tank.hpp"

void Tank::fire()
{

	double xComp = (  this->turretTip.x - this->turretBase.x ) / (double)this->tankLength;
	double yComp = ( this->turretTip.y - this->turretBase.y ) / (double)this->tankLength;
	double velo = 10.0f;

	this->shells.emplace_back(
		Projectile( this->turretTip, velo * xComp, velo * yComp,
			this->points, this->blockSize) );

}

void Tank::updateTank()
{
	this->updateTurret();

	//updating the tanks shells
	for(size_t i = 0; i < this->shells.size(); ++i)
		this->shells.at(i).updateShell();
        
}

void Tank::updateTurret()
{
	float mouseX = GetMouseX();
	float mouseY = GetMouseY();

	float turretBaseX = this->xpos + this->tankLength / 2;
	float turretBaseY = this->ypos - this->tankLength / 8;

	float bigHyp = std::sqrt( 
		(mouseX - turretBaseX) * (mouseX - turretBaseX) +
		(mouseY - turretBaseY) * (mouseY - turretBaseY) );
	float turretY = ( ( this->tankLength * (mouseY - turretBaseY)) / bigHyp );
	float turretX = std::sqrt( this->tankLength * this->tankLength - (turretY * turretY) );

	float turretTipX = turretBaseX + turretX;
	float turretTipY = turretBaseY + turretY;

	Vector2 turretBase = {turretBaseX, turretBaseY};
	Vector2 turretTip = {turretTipX, turretTipY};

	this->turretBase = turretBase;
	this->turretTip = turretTip;
}

void Tank::drawTank()
{
	//tank body
	DrawRectangle(this->xpos, this->ypos, this->tankLength, this->tankHeight, DARKGREEN);
	DrawCircle(this->xpos + this->tankLength / 2, this->ypos, this->tankLength / 4, DARKGREEN);

	//tank turret
	DrawLineEx(this->turretBase, this->turretTip, 2.0, DARKGREEN);

	//tanks outgoing shells
	for(auto shell : this->shells)
                shell.drawShell();

}

Tank::Tank(std::vector<int> &p, int blockSize):
points{p}, blockSize{blockSize}
{

	this->xpos = 20;
	this->ypos = this->points.at(0) - 10;
	this->tankLength = 20;
	this->tankHeight = 10;

}
