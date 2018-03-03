#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SplashScreen.h"
#include "RoundaboutEngine.h"

void SplashScreen::Show(sf::RenderWindow &renderWindow) {

	sf::Texture image;
	if (image.loadFromFile("Images/splashscreen.png") != true) {
		image.loadFromFile("Images/splashscreen.png");
		image.setSmooth(true);
		return;
	}

	sf::Sprite sprite;
	sprite.setTexture(image);
	renderWindow.draw(sprite);
	renderWindow.display();
}
