#include "Particle.h"

Particle::Particle(int x, int y) {
	arrivalTime = 0;
	xPosition = x;
	yPosition = y;
	point.setSize(sf::Vector2f(1, 1));
	point.setFillColor(sf::Color::White);
	point.setPosition((float)x, (float)y);
}

void Particle::update(sf::RenderWindow& window) {
	walk();
	point.setPosition((float)xPosition, (float)yPosition);
	draw(window);
	std::cout << xPosition << std::endl << yPosition << std::endl;
}

void Particle::walk() {
	switch (1 + std::rand() % 6 ) {
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

void Particle::draw(sf::RenderWindow& window) {
	window.draw(point);
}