#include "Particle.h"

Particle::Particle(int x, int y, bool seed) {
	arrivalTime = 0;
	srand(time(NULL));
	isStatic = seed;
	if (seed == true) {
		xPosition = x;
		yPosition = y;
		point.setFillColor(sf::Color::Green);
	} else {
		randomLocation();
		point.setFillColor(sf::Color::White);
	}
	point.setSize(sf::Vector2f(1, 1));
	point.setPosition((float)x, (float)y);
}

void Particle::update(sf::RenderWindow& window, std::vector<Particle>& particles) {
	if (!isStatic) {
		walk();
	} else {
		for (int i = 0; i < particles.size(); i++) {
			if (&particles[i] != this) {
				if (particles[i].getIsStatic() == false) {
					if (abs(particles[i].getX() - xPosition) <= 1 && abs(particles[i].getY() - yPosition) <= 1) {
						particles[i].setIsStatic(true);
					}
				}
			}
		}
	}
	point.setPosition((float)xPosition, (float)yPosition);
	draw(window);
}

void Particle::walk() {
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

void Particle::randomLocation() {
	xPosition = rand() % 600;
	yPosition = rand() % 600;
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