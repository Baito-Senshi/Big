#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow) {
	sf::Texture image;

	if (image.loadFromFile("images/SplashScreen.png") != true) {
		image.loadFromFile("images/SplashScreen.png");
		image.setSmooth(true);
		return;
	}

	sf::Sprite sprite;
	sprite.setTexture(image);

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;

	//If current game state is Initialized
	while (RoundaboutEngine::_gameState != RoundaboutEngine::GameState::Initialized) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				//Changing gamestate to showing splash
				RoundaboutEngine::_gameState = RoundaboutEngine::GameState::ShowingSplash;
				return;
			}
		}
	}
}
