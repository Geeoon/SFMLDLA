#include "Scene.h"

Scene::Scene() {
	particles.reset(new ParticleManager(160000, ui.getTexture()));
}

void Scene::start() {
	while (ui.getWindow().isOpen()) {
		ui.pollEvent();
		
		particles->update();

		ui.getTexture().display();
		ui.getWindow().clear();
		sf::Sprite sprite(ui.getTexture().getTexture());
		ui.getWindow().draw(sprite);
		ui.getWindow().display();

	}
}