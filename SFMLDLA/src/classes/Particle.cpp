#include "Particle.h"

Particle::Particle(int x, int y, bool seed, int r, std::vector<std::vector<int>> *board, sf::RenderTexture *window, size_t *pStatic) {
	arrivalTime = 0;
	startTime = 0;
	nStatic = pStatic;
	windowP = window;
	windowX = (*windowP).getSize().x;
	windowY = (*windowP).getSize().y;
	boardP = board;
	xPosition = 0;
	yPosition = 0;
	radius = r;
	srand(time(NULL));
	isStatic = seed;
	point.setSize(sf::Vector2f(radius, radius));
	if (seed == true) {
		xPosition = x;
		yPosition = y;
		setIsStatic();
	} else {
		point.setFillColor(sf::Color::White);
	}
}

int Particle::update() {
	if (!isStatic) {
		walk();
		(*boardP)[xPosition][yPosition] = 1;
		if (xPosition == 0) { //left
			if (yPosition == 0) {//topleft
				if ((*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2) {
					setIsStatic();
					return 1;
				}
			} else if (yPosition == windowY - 1) {//bottomleft
				if ((*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2) {
					setIsStatic();
					return 1;
				}
			} else {//middleleft
				if ((*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2) {
					setIsStatic();
					return 1;
				}
			}
		} else if (xPosition == windowX - 1) {//right
			if (yPosition == 0) {//topright
				if ((*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2) {
					setIsStatic();
					return 1;
				}
			} else if (yPosition == windowY - 1) {//bottomlright
				if ((*boardP)[xPosition][yPosition] == 2 || (*boardP)[xPosition][yPosition] == 2) {
					setIsStatic();
					return 1;
				}
			} else {//middleright
				if ((*boardP)[xPosition][yPosition + 1] == 2 || (*boardP)[xPosition][yPosition - 1] == 2 || (*boardP)[xPosition - 1][yPosition] == 2) {
					setIsStatic();
					return 1;
				}
			}
		} else {//middle
			if (yPosition == 0) {//top middle
				if ((*boardP)[xPosition][yPosition + 1] == 2 || (*boardP)[xPosition + 1][yPosition] == 2 || (*boardP)[xPosition - 1][yPosition] == 2) {
					setIsStatic();
					return 1;
				}
			} else if (yPosition == windowY - 1) {//bottom middle
				if ((*boardP)[xPosition][yPosition - 1] == 2 || (*boardP)[xPosition + 1][yPosition] == 2 || (*boardP)[xPosition - 1][yPosition] == 2) {
					setIsStatic();
					return 1;
				}
			} else {//middle middle

				if ((*boardP)[xPosition][yPosition + 1] == 2 || (*boardP)[xPosition][yPosition - 1] == 2 || (*boardP)[xPosition + 1][yPosition] == 2 || (*boardP)[xPosition - 1][yPosition] == 2) {
					setIsStatic();
					return 1;
				}
			}
		}
	}
	return 0;
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

void Particle::setIsStatic() {
	isStatic = true;
	sf::Color color((std::sin(sqrt((float)(*nStatic)) / (float)100) + 1) * (255 / 2), 0, 150);
	point.setFillColor(color);
	(*boardP)[xPosition][yPosition] = 2;
	point.setPosition((float)xPosition, (float)yPosition);
	(*windowP).draw(point);
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

sf::RectangleShape Particle::getRectangle() {
	return point;
}