#include "ParticleManager.h"

ParticleManager::ParticleManager(int size) {
	particles.resize(size, Particle(0, 0, false));
	particles.push_back(Particle(300, 300, true)); //this is the seed
}

void ParticleManager::update(sf::RenderWindow& window) {
	for (int i = 0; i < particles.size(); i++) {
		particles[i].update(window);
	}
}