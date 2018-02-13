#include "RoundaboutEngine.h"

void RoundaboutEngine::Start(void)
{
	//If gamestate is not Uninitialized change it to Initialized
	if (_gameState != Uninitialized)
	{
		_gameState = Initialized;
		return;
	}

	//Draw window and change gamestate to Playing
	sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "Roundabout Engine");
	_gameState = RoundaboutEngine::Playing;

	while (_gameState)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}
}

void RoundaboutEngine::Initialize(void)
{
	_gameState = Uninitialized;
	// check for memory
	//check for hd
	//check for processor 
	// if passed change game state to initialized otherwise change to uninti

	//_gameState = Initialized;
	return;
}


bool RoundaboutEngine::IsExiting()
{
	return false;
}

void RoundaboutEngine::GameLoop(void)
{
	return;
}

