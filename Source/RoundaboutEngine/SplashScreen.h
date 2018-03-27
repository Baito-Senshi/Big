#pragma once

class SplashScreen {
public:
	void Show(sf::RenderWindow& window);

	sf::Texture image;
	sf::Sprite sprite;

	sf::Event event;
};