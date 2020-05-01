#pragma once
#include <cstdlib>
#include <ctime>
#include "SFML/Graphics.hpp"

class Particle
{
public:
	Particle(int x, int y, bool seed);
	void update(sf::RenderWindow& window);
	void setIsStatic(bool s);
	bool getIsStatic();
private:
	void walk();
	void draw(sf::RenderWindow& window);
	sf::RectangleShape point;
	int xPosition;
	int yPosition;
	double arrivalTime;
	bool isStatic = false;
};

