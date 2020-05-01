#include "Scene.h"

Scene::Scene() {
	particles.reset(new ParticleManager(10000));
}

void Scene::start() {
	while (ui.getWindow().isOpen()) {
		ui.pollEvent();
		ui.getWindow().clear();

		particles->update(ui.getWindow());

		ui.getWindow().display();
	}
}