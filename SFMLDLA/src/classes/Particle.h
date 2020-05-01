#pragma once
#include <cstdlib>
#include <iostream> //For debug only; delete later
#include "SFML/Graphics.hpp"

class Particle
{
public:
	Particle(int x, int y);
	void update(sf::RenderWindow& window);

private:
	void walk();
	void draw(sf::RenderWindow& window);
	sf::RectangleShape point;
	int xPosition;
	int yPosition;
	double arrivalTime;
};

