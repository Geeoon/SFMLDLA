#pragma once
#include "SFML/Graphics.hpp"
class UIManager
{
public:
	UIManager();
	void pollEvent(/*std::vector<std::vector<int>>& board*/);
	sf::RenderWindow& getWindow();
	sf::RenderTexture& getTexture();
private:
	sf::RenderWindow window;
	sf::RenderTexture texture;
};

