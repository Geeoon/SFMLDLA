#include "Particle.h"

Particle::Particle(int x, int y, bool seed, int r) {
	arrivalTime = 0;
	radius = r;
	srand(time(NULL));
	isStatic = seed;
	if (seed == true) {
		xPosition = x;
		yPosition = y;
		point.setFillColor(sf::Color::Green);
	} else {
		point.setFillColor(sf::Color::White);
	}
	point.setSize(sf::Vector2f(radius, radius));
	point.setPosition((float)x, (float)y);
}

void Particle::update(sf::RenderWindow& window, std::vector<Particle>& particles) {
	if (!isStatic) {
		walk(window);
	} else {
		for (int i = 0; i < particles.size(); i++) {
			if (&particles[i] != this) {
				if (particles[i].getIsStatic() == false) {
					if (abs(particles[i].getX() - xPosition) <= radius && abs(particles[i].getY() - yPosition) <= radius) {
						particles[i].setIsStatic(true);
					}
				}
			}
		}
	}
	point.setPosition((float)xPosition, (float)yPosition);
	draw(window);
}

void Particle::walk(sf::RenderWindow& window) {
	if (!isStatic) {
		switch (1 + rand() % 6) {
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

	if (xPosition < 0) {
		xPosition = 0;
	} else if (xPosition > window.getSize().x) {
		xPosition = window.getSize().x;
	}
	
	if (yPosition < 0) {
		yPosition = 0;
	} else if (yPosition > window.getSize().y) {
		yPosition = window.getSize().y;
	}


	
}

void Particle::draw(sf::RenderWindow& window) {
	window.draw(point);
}

void Particle::setIsStatic(bool s) {
	isStatic = s;
	if (isStatic == true) {
		point.setFillColor(sf::Color::Green);
	} else {
		point.setFillColor(sf::Color::White);
	}
}

bool Particle::getIsStatic() {
	return isStatic;
}

void Particle::setSeed(double seed) {
	srand(seed);
}
void Particle::setLocation(int x, int y) {
	xPosition = x;
	yPosition = y;
}

int Particle::getX() {
	return xPosition;
}

int Particle::getY() {
	return yPosition;
}

sf::RectangleShape Particle::getRectangle() {
	return point;
}