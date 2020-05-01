#pragma once
#include <cstdlib>
#include <stdlib.h> 
#include <ctime>
#include <vector>
#include "SFML/Graphics.hpp"

class Particle
{
public:
	Particle(int x, int y, bool seed, int r);
	void update(sf::RenderWindow& window, std::vector<Particle>& particles);
	void setIsStatic(bool s);
	bool getIsStatic();
	void setSeed(double seed);
	void randomLocation();
	void setLocation(int x, int y);
	int getX();
	int getY();
	sf::RectangleShape getRectangle();
private:
	void walk(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	sf::RectangleShape point;
	int xPosition;
	int yPosition;
	double arrivalTime;
	bool isStatic = false;
	int radius;
};

