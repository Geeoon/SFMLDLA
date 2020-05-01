#include "Scene.h"

Scene::Scene() {
	particles.reset(new ParticleManager(1000, ui.getWindow()));
}

void Scene::start() {
	while (ui.getWindow().isOpen()) {
		ui.pollEvent();
		ui.getWindow().clear();

		particles->update(ui.getWindow());

		ui.getWindow().display();
	}
}