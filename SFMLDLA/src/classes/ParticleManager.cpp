#include "ParticleManager.h"

ParticleManager::ParticleManager(int size, sf::RenderWindow& window) {
	srand((unsigned int)time(NULL));
	particles.resize(size, Particle(0, 0, false, 2));
	for (size_t i = 0; i < particles.size(); i++) {
		particles[i].setLocation(1 + rand() % (int)(window.getSize().x), 1 + rand() % (int)(window.getSize().y));
	}
	particles.push_back(Particle(window.getSize().x / 2, window.getSize().y / 2, true, 2)); //this is the seed
}

void ParticleManager::update(sf::RenderWindow& window) {
	for (size_t i = 0; i < particles.size(); i++) {
		particles[i].update(window, particles);
	}
}