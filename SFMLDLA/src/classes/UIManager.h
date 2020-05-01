#pragma once
#include "SFML/Graphics.hpp"
class UIManager
{
public:
	UIManager();
	void pollEvent();
	sf::RenderWindow& getWindow();
private:
	sf::RenderWindow window;
};

