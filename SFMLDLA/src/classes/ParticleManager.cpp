#include "ParticleManager.h"

ParticleManager::ParticleManager(int size, sf::RenderWindow& window) {
	board.resize(window.getSize().x, std::vector<int>(window.getSize().y));
	srand((unsigned int)time(NULL));
	particles.resize(size, Particle(0, 0, false, radius, board));
	for (size_t i = 0; i < particles.size(); i++) {
		particles[i].setLocation(rand() % (int)(window.getSize().x), rand() % (int)(window.getSize().y), board);
	}
	particles.push_back(Particle(window.getSize().x / 2, window.getSize().y / 2, true, radius, board)); //this is the seed
}

void ParticleManager::update(sf::RenderWindow& window) {
	for (size_t i = 0; i < particles.size(); i++) {
		particles[i].update(window, particles, board);
	}
}