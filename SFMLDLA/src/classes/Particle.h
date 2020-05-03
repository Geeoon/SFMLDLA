#pragma once
#include <cstdlib>
#include <stdlib.h> 
#include <ctime>
#include <vector>
#include "SFML/Graphics.hpp"

class Particle
{
public:
	Particle(int x, int y, bool seed, int r, std::vector<std::vector<int>> *board, sf::RenderTexture *window, size_t *pStatic);
	int update();
	void setIsStatic();
	bool getIsStatic();
	void setSeed(double seed);
	void setLocation(int x, int y);
	sf::RectangleShape getRectangle();
private:
	void walk();
	sf::RenderTexture *windowP;
	sf::RectangleShape point;
	std::vector<std::vector<int>> *boardP;
	size_t *nStatic;
	int xPosition;
	int yPosition;
	double arrivalTime;
	double startTime;
	bool isStatic = false;
	int radius;
	int windowX = 0;
	int windowY = 0;
};

