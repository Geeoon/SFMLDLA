#include "Particle.h"

Particle::Particle(int x, int y, bool seed, int r, std::vector<std::vector<int>> *board, sf::RenderWindow *window) {
	windowP = window;
	windowX = (*windowP).getSize().x;
	windowY = (*windowP).getSize().y;
	boardP = board;
	xPosition = 0;
	yPosition = 0;
	arrivalTime = 0;
	startTime = time(nullptr);
	radius = r;
	srand(time(NULL));
	isStatic = seed;
	if (seed == true) {
		xPosition = x;
		yPosition = y;
		(*boardP)[xPosition][yPosition] = 2;
		point.setFillColor(sf::Color(0, 0, 150));
	} else {
		point.setFillColor(sf::Color::White);
	}
	point.setSize(sf::Vector2f(radius, radius));
	point.setPosition((float)x, (float)y);
}

void Particle::update() {
	if (!isStatic) {
		walk();
		(*boardP)[xPosition][yPosition] = 1;
		if (xPosition == 0) { //left
			if (yPosition == 0) {//topleft
				if ((*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2) {
					setIsStatic(true);
				}
			} else if (yPosition == windowX - 1) {//bottomleft
				if ((*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2) {
					setIsStatic(true);
				}
			} else {//middleleft
				if ((*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2) {
					setIsStatic(true);
				}
			}
		} else if (xPosition == windowX - 1) {//right
			if (yPosition == 0) {//topright
				if ((*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2) {
					setIsStatic(true);
				}
			} else if (yPosition == windowX - 1) {//bottomlright
				if ((*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2) {
					setIsStatic(true);
				}
			} else {//middleright
				if ((*boardP)[xPosition][yPosition + 1] == 2 || (*boardP)[xPosition][yPosition - 1] == 2 || (*boardP)[xPosition - 1][yPosition] == 2) {
					setIsStatic(true);
				}
			}
		} else {//middle
			if (yPosition == 0) {//top middle
				if ((*boardP)[xPosition][yPosition + 1] == 2 || (*boardP)[xPosition + 1][yPosition] == 2 || (*boardP)[xPosition - 1][yPosition] == 2) {
					setIsStatic(true);
				}
			} else if (yPosition == windowX - 1) {//bottom middle
				if ((*boardP)[xPosition][yPosition - 1] == 2 || (*boardP)[xPosition + 1][yPosition] == 2 || (*boardP)[xPosition - 1][yPosition] == 2) {
					setIsStatic(true);
				}
			} else {//middle middle

				if ((*boardP)[xPosition][yPosition + 1] == 2 || (*boardP)[xPosition][yPosition - 1] == 2 || (*boardP)[xPosition + 1][yPosition] == 2 || (*boardP)[xPosition - 1][yPosition] == 2) {
					setIsStatic(true);
				}
			}
		}
		//point.setPosition((float)xPosition, (float)yPosition);
		//(*windowP).draw(point); //uncomment these two lines to show particles
	} else {
		(*windowP).draw(point);
	}
}

void Particle::walk() {
	switch (1 + rand() % 4) {
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
	//Prevents particles from going out of bounds.
	if (xPosition < 0) {
		xPosition = 0;
	} else if (xPosition > windowX - 1) {
		xPosition = windowX - 1;
	}

	if (yPosition < 0) {
		yPosition = 0;
	} else if (yPosition > windowY - 1) {
		yPosition = windowY - 1;
	}
}

void Particle::setIsStatic(bool s) {
	isStatic = s;
	if (isStatic == true) {
		arrivalTime = time(nullptr);
		double timeDif = (arrivalTime - startTime);
		sf::Color color((std::sin(timeDif / 255) + 1) * (255 / 2), 0, 150);
		point.setFillColor(color);
		(*boardP)[xPosition][yPosition] = 2;
		point.setPosition((float)xPosition, (float)yPosition);
	} else {
		point.setFillColor(sf::Color::Black);
	}
}

bool Particle::getIsStatic() {
	return isStatic;
}

void Particle::setSeed(double seed) {
	srand(seed);
}
void Particle::setLocation(int x, int y) {
	(*boardP)[xPosition][yPosition] = 0;
	xPosition = x;
	yPosition = y;
	(*boardP)[xPosition][yPosition] = 1;
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