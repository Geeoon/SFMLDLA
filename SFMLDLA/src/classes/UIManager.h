#pragma once
#include "SFML/Graphics.hpp"
class UIManager
{
public:
	UIManager(int x, int y, bool fullscreen);
	void pollEvent(/*std::vector<std::vector<int>>& board*/);
	sf::RenderWindow& getWindow();
	sf::RenderTexture& getTexture();
	void saveDLA();
	void start(int x, int y);
private:
	sf::RenderWindow window;
	sf::RenderTexture texture;
};

