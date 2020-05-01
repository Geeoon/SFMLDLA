#pragma once
#include <vector>
#include "Particle.h"

class ParticleManager
{
public:
	ParticleManager(int size);
	void update(sf::RenderWindow& window);

private:
	std::vector<Particle> particles;
};

