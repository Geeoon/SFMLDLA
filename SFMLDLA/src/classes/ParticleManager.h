#pragma once
#include <vector>
#include "Particle.h"

class ParticleManager
{
public:
	ParticleManager(int size, sf::RenderWindow& window);
	void update();
	std::vector<std::vector<int>>& getBoard();
private:
	std::vector<Particle> particles;
	std::vector<std::vector<int>> board;
	int radius = 1;
};

