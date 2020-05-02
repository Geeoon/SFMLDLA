#include "Scene.h"

Scene::Scene() {
	particles.reset(new ParticleManager(10000, ui.getWindow()));
}

void Scene::start() {
	while (ui.getWindow().isOpen()) {
		ui.pollEvent(particles->getBoard());
		ui.getWindow().clear();

		particles->update(ui.getWindow());

		ui.getWindow().display();
	}
}