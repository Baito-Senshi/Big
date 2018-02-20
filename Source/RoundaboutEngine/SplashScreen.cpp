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

	sf::Event event;
	RoundaboutEngine engine;
	
	//If current game state is Initialized
	while(RoundaboutEngine::GameState::Initialized != RoundaboutEngine::GameState::Initialized) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				//Changing gamestate to showing splash
				engine._gameState = engine.ShowingSplash;
				return;
			}
		}
	}
}
