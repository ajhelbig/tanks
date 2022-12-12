#include "terrain.hpp"

Terrain::Terrain(const int windowWidth, const int windowHeight, int blockSize, int slope, int smooth) :
windowWidth{windowWidth}, windowHeight{windowHeight}, blockSize{blockSize}, slope{slope}, smooth{smooth}
{
	
	this->generatePoints();

	this->smoothPoints();

	this->generateBlocks();

}

void Terrain::generateBlocks()
{

}

void Terrain::smoothPoints()
{
	int brushSize = 2 * smooth + 1;
	std::vector<int> smoothedPoints;
	int numPoints = this->points.size();

	for(int i = 0; i < numPoints; ++i)
	{
		int sum = 0;

		for(int j = 0; j < brushSize; ++j)
		{
			if( i >= this->smooth && i <= numPoints - 1 - this->smooth)
				sum += this->points.at(i - this->smooth + j);

			else if( i < this->smooth )
				sum += this->points.at(j);

			else
				sum += this->points.at(numPoints - brushSize + j);			
			
		}

		sum /= brushSize;

		smoothedPoints.push_back(sum);
	}

	for(int i = 0; i < numPoints; ++i)
		this->points.at(i) = smoothedPoints.at(i);
}

void Terrain::generatePoints()
{
	//generate random starting point from a 
	std::default_random_engine generator (std::time(0));
  	std::normal_distribution<double> distribution(0.0, this->windowHeight / 10);

	double start = distribution(generator);

	this->points.push_back((this->windowHeight - this->windowHeight / 4) + start);

	for(int i = 0; i < (this->windowWidth / this->blockSize); ++i)
	{
		double point = points.at(i) - this->windowHeight / 2.0;
		point = point / (this->windowHeight / 2.0);

		double distFunct = -1.0 * (point * point) + 1.0;
		if(distFunct < 0) distFunct = 0;
		if(distFunct > 1) distFunct = 1;

		int top = this->blockSize * this->slope;
		int bottom = -1 * this->blockSize * this->slope;

		if(point < 0) top *= distFunct;
		else bottom *= distFunct;

		int range = top - bottom;

		int offset = -1 * (std::rand() % (range) + bottom);

		this->points.push_back(points.at(i) + offset);
	}
}

void Terrain::drawTerrain()
{

	for(int i = 0; i < points.size() - 1; ++i)
		DrawLine(i * this->blockSize, points.at(i), (i + 1) * this->blockSize, points.at(i + 1), WHITE);
	
}