#pragma once
#include "SFML/Graphics.hpp"
class UIManager
{
public:
	UIManager();
	void pollEvent(std::vector<std::vector<int>>& board);
	sf::RenderWindow& getWindow();
private:
	sf::RenderWindow window;
};

