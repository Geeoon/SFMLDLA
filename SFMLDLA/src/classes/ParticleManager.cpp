#include "ParticleManager.h"

ParticleManager::ParticleManager(int size) {
	srand((unsigned int)time(NULL));
	particles.resize(size, Particle(0, 0, false));
	for (size_t i = 0; i < particles.size(); i++) {
		particles[i].setLocation((1 + rand() % 600), (1 + rand() % 600));
	}
	particles.push_back(Particle(300, 300, true)); //this is the seed
}

void ParticleManager::update(sf::RenderWindow& window) {
	for (size_t i = 0; i < particles.size(); i++) {
		particles[i].update(window);
	}
}