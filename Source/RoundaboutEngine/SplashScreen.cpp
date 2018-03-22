#include "SFML/Graphics.hpp"
#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow &renderWindow) 
{

	if (image.loadFromFile("Images/splashscreen.png") != true)
	{
		image.loadFromFile("Images/splashscreen.png");
		image.setSmooth(true);
		return;
	}

	sprite.setTexture(image);
	renderWindow.draw(sprite);
	renderWindow.display();

	while (renderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::KeyPressed
			|| event.type == sf::Event::EventType::MouseButtonPressed
			|| event.type == sf::Event::EventType::Closed)
		{
			return;
		}
	}
}
