#include "projectile.hpp"

void Projectile::updateShell()
{
	//determining the line below the shell
	float p1yIndex = std::ceil(this->pos.x / this->blockSize);
	float p1y = this->points.at(p1yIndex);
	float p1x = p1yIndex * this->blockSize;

	float p2yIndex = std::floor(this->pos.x / this->blockSize);
	float p2y = this->points.at(p2yIndex);
	float p2x = p2yIndex * this->blockSize;

	Vector2 p1 = {p1x, p1y};
	Vector2 p2 = {p2x, p2y};

	//CheckCollisionPointLine(Vector2 point, Vector2 p1, Vector2 p2, int threshold);
	//shell collision
	if( CheckCollisionPointLine(this->pos, p1, p2, 5) )
		this->terminate();

	else if( this->pos.y >= p1.y && this->pos.y >= p2.y)
		this->terminate();

	else if( this->pos.x >= this->blockSize * (this->points.size() - 2))
	{
		this->terminate();
		this->pos.x = (this->blockSize * (this->points.size() - 1));
	}

	this->pos.x += this->xvelo;
	this->pos.y += this->yvelo;
	this->yvelo += this->yaccel;
}

void Projectile::terminate()
{
	this->xvelo = 0;
	this->yvelo = 0;
	this->yaccel = 0;
	DrawCircleV(this->pos, 5, ORANGE);
}

void Projectile::drawShell()
{
	DrawCircle(this->pos.x, this->pos.y, 2, RED);
}

Projectile::Projectile(Vector2 pos, float xvelo, float yvelo, 
	std::vector<int> &p, int blockSize): 
pos{pos}, xvelo{xvelo}, yvelo{yvelo}, points{p}, blockSize{blockSize}
{
	this->yaccel = 0.02;
}
