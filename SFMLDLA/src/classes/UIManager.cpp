#include "UIManager.h"

UIManager::UIManager() {
	window.create(sf::VideoMode(600, 600), "Diffusion-Limited Aggregation");
}

void UIManager::pollEvent() {
	sf::Event event;
	while (window.pollEvent(event)) { 
		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window.setView(sf::View(visibleArea));
		}

		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

sf::RenderWindow& UIManager::getWindow() {
	return window;
}