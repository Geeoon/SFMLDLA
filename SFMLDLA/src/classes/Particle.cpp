#include "Particle.h"

Particle::Particle(int x, int y, bool seed) {
	arrivalTime = 0;
	srand(time(0));
	isStatic = seed;
	if (seed == true) {
		xPosition = x;
		yPosition = y;
		point.setFillColor(sf::Color::Green);
	} else {
		xPosition = std::rand() % 600;
		yPosition = std::rand() % 600;
		point.setFillColor(sf::Color::White);
	}
	point.setSize(sf::Vector2f(1, 1));
	point.setPosition((float)x, (float)y);
}

void Particle::update(sf::RenderWindow& window) {
	if (!isStatic) {
		walk();
	} else {

	}
	point.setPosition((float)xPosition, (float)yPosition);
	draw(window);
}

void Particle::walk() {
	if (!isStatic) {
		switch (1 + std::rand() % 6) {
		case 1:
			xPosition += 1;
			break;
		case 2:
			xPosition -= 1;
			break;
		case 3:
			yPosition += 1;
			break;
		case 4:
			yPosition -= 1;
			break;
		default:
			break;
		}
	}

	//Prevents particles from going out of bounds.
	if (xPosition > 600) {
		xPosition = 600;
	} else if (xPosition < 0) {
		xPosition = 0;
	}

	if (yPosition > 600) {
		yPosition = 600;
	} else if (yPosition < 0) {
		yPosition = 0;
	}
	
}

void Particle::draw(sf::RenderWindow& window) {
	window.draw(point);
}

void Particle::setIsStatic(bool s) {
	isStatic = s;
}

bool Particle::getIsStatic() {
	return isStatic;
}