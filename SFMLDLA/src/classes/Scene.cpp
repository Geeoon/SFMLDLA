#include "Scene.h"

Scene::Scene() {
	getInput();
	ui.start(xresolution, yresolution);
	particles.reset(new ParticleManager(nParticles, ui.getTexture()));
	
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
		if (particles->isDone() && isDone == false) {
			isDone = true;
			ui.saveDLA();
			std::cout << "Done.  Image saved as DLA.PNG";
		}
	}
}

void Scene::getInput() {
	std::cout << "Resolution (can only be square, so input one length; if you aren't sure, just put 800): ";
	std::cin >> xresolution;
	yresolution = xresolution;
	std::cout << "Number of particles (if you aren't sure, just put 160000): ";
	std::cin >> nParticles;
}