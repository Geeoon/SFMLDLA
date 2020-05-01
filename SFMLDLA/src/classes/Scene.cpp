#include "Scene.h"

Scene::Scene() {

}

void Scene::start() {
	Particle test(0, 0);
	while (ui.getWindow().isOpen()) {
		ui.pollEvent();
		ui.getWindow().clear();

		test.update(ui.getWindow());

		ui.getWindow().display();
	}
}