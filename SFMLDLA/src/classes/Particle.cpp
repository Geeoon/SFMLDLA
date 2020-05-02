#include "Particle.h"

Particle::Particle(int x, int y, bool seed, int r, std::vector<std::vector<int>>& board) {
	xPosition = 0;
	yPosition = 0;
	arrivalTime = 0;
	radius = r;
	srand(time(NULL));
	isStatic = seed;
	if (seed == true) {
		xPosition = x;
		yPosition = y;
		board[xPosition][yPosition] = 2;
		point.setFillColor(sf::Color::White);
	} else {
		point.setFillColor(sf::Color::White);
	}
	point.setSize(sf::Vector2f(radius, radius));
	point.setPosition((float)x, (float)y);
}

void Particle::update(sf::RenderWindow& window, std::vector<Particle>& particles, std::vector<std::vector<int>>& board) {
	board[xPosition][yPosition] = 0;
	if (!isStatic) {;
		walk(window);
		board[xPosition][yPosition] = 1;
		if (board[xPosition][yPosition + 1] == 2) {
			isStatic = true;
		}
		if (board[xPosition][yPosition - 1] == 2) {
			isStatic = true;
		}
		if (board[xPosition + 1][yPosition] == 2) {
			isStatic = true;
		}
		if (board[xPosition - 1][yPosition] == 2) {
			isStatic = true;
		}
		board[xPosition][yPosition] = 2;
	} else {/*
		for (int i = 0; i < particles.size(); i++) {
			if (&particles[i] != this) {
				if (particles[i].getIsStatic() == false) {
					if (abs(particles[i].getX() - xPosition) <= radius && abs(particles[i].getY() - yPosition) <= radius) {
						particles[i].setIsStatic(true);
					}
				}
			}
		}
		if (xPosition == 0) { //left
			if (yPosition == 0) {//topleft

			} else if (yPosition == window.getSize().x) {//bottomleft

			} else {//middleleft

			}
		} else if (xPosition == window.getSize().x) {//right
			if (yPosition == 0) {//topright

			} else if (yPosition == window.getSize().x) {//bottomlright

			} else {//middleright

			}
		} else {//middle
			if (yPosition == 0) {//top middle

			} else if (yPosition == window.getSize().x) {//bottom middle

			} else {//middle middle

			}
		}
		*/

		board[xPosition][yPosition] = 2;
	}
	point.setPosition((float)xPosition, (float)yPosition);
	draw(window);
}

void Particle::walk(sf::RenderWindow& window) {
	if (xPosition == 0) { //left
		if (yPosition == 0) {//topleft
			switch (1 + rand() % 2) {
			case 1:
				xPosition += 1;
				break;
			case 2:
				yPosition += 1;
				break;
			default:
				break;
			}
		} else if (yPosition == window.getSize().x) {//bottomleft
			switch (1 + rand() % 2) {
			case 1:
				xPosition += 1;
				break;
			case 2:
				xPosition -= 1;
				break;
			default:
				break;
			}
		} else {//middleleft
			switch (1 + rand() % 3) {
			case 1:
				xPosition += 1;
				break;
			case 2:
				yPosition -= 1;
				break;
			case 3:
				yPosition += 1;
				break;
			default:
				break;
			}
		}
	} else if (xPosition == window.getSize().x) {//right
		if (yPosition == 0) {//topright
			switch (1 + rand() % 2) {
			case 1:
				xPosition -= 1;
				break;
			case 2:
				yPosition += 1;
				break;
			default:
				break;
			}
		} else if (yPosition == window.getSize().x) {//bottomlright
			switch (1 + rand() % 2) {
			case 1:
				xPosition -= 1;
				break;
			case 2:
				xPosition -= 1;
				break;
			default:
				break;
			}
		} else {//middleright
			switch (1 + rand() % 3) {
			case 1:
				xPosition -= 1;
				break;
			case 2:
				yPosition -= 1;
				break;
			case 3:
				yPosition += 1;
				break;
			default:
				break;
			}
		}
	} else {//middle
		if (yPosition == 0) {//top middle
			switch (1 + rand() % 3) {
			case 1:
				xPosition += 1;
				break;
			case 2:
				xPosition -= 1;
				break;
			case 3:
				yPosition += 1;
				break;
			default:
				break;
			}
		} else if (yPosition == window.getSize().x) {//bottom middle
			switch (1 + rand() % 3) {
			case 1:
				xPosition += 1;
				break;
			case 2:
				xPosition -= 1;
				break;
			case 3:
				yPosition -= 1;
				break;
			default:
				break;
			}
		} else {//middle middle
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
		}
	}
	

	/*
	if (!isStatic) {
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
	*/

	
}

void Particle::draw(sf::RenderWindow& window) {
	window.draw(point);
}

void Particle::setIsStatic(bool s) {
	isStatic = s;
	if (isStatic == true) {
		point.setFillColor(sf::Color::White);
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
void Particle::setLocation(int x, int y, std::vector<std::vector<int>>& board) {
	board[xPosition][yPosition] = 0;
	xPosition = x;
	yPosition = y;
	board[xPosition][yPosition] = 1;
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