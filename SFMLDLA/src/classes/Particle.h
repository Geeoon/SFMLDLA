#pragma once
#include <cstdlib>
#include <stdlib.h> 
#include <ctime>
#include <vector>
#include "SFML/Graphics.hpp"

class Particle
{
public:
	Particle(int x, int y, bool seed, int r, std::vector<std::vector<int>> *board, sf::RenderTexture *window);
	int update();
	void setIsStatic(bool s);
	bool getIsStatic();
	void setSeed(double seed);
	void setLocation(int x, int y);
	int getX();
	int getY();
	sf::RectangleShape getRectangle();
private:
	void walk();
	sf::RenderTexture *windowP;
	sf::RectangleShape point;
	std::vector<std::vector<int>> *boardP;
	int xPosition;
	int yPosition;
	double arrivalTime;
	double startTime;
	bool isStatic = false;
	int radius;
	int windowX = 0;
	int windowY = 0;
};

