#include "UIManager.h"

UIManager::UIManager() {
	window.create(sf::VideoMode(100, 100), "Diffusion-Limited Aggregation", sf::Style::Close);
}

void UIManager::start(int x, int y) {
	window.setSize(sf::Vector2u(x, y));
	texture.create(window.getSize().x, window.getSize().y);
	texture.clear(sf::Color::Black);
}

void UIManager::pollEvent(/*std::vector<std::vector<int>>& board*/) {
	sf::Event event;
	while (window.pollEvent(event)) { 
		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window.setView(sf::View(visibleArea));
			//board.resize(window.getSize().x, std::vector<int>(window.getSize().y));
		}

		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

sf::RenderWindow& UIManager::getWindow() {
	return window;
}

sf::RenderTexture& UIManager::getTexture() {
	return texture;
}

void UIManager::saveDLA() {
	texture.getTexture().copyToImage().saveToFile("DLA.png");
}