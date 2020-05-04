#pragma once
#include <vector>
#include <iostream>
#include "Particle.h"

class ParticleManager
{
public:
	ParticleManager(int size, sf::RenderTexture& window);
	~ParticleManager();
	void update();
	std::vector<std::vector<int>>& getBoard();
	bool isDone();
private:
	std::vector<Particle> particles;
	std::vector<std::vector<int>> board;
	size_t staticParticles = 5;
	int radius = 1;
};

