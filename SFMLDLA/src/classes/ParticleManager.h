#pragma once
#include <vector>
#include <iostream>
#include "Particle.h"

class ParticleManager
{
public:
	ParticleManager(int size, sf::RenderTexture& window);
	void update();
	std::vector<std::vector<int>>& getBoard();
private:
	std::vector<Particle> particles;
	std::vector<std::vector<int>> board;
	int staticParticles = 1;
	int radius = 1;
};

