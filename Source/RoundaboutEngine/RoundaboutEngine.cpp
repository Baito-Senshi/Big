#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "RoundaboutEngine.h"

class RoundaboutEngine
{
public:
	static void Start();
	static void Initialize();

private:
	static bool IsExiting();
	static void GameLoop();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};

void RoundaboutEngine::Start(void)
{
	if (_gameState != Uninitialized)
		return;
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

}


bool RoundaboutEngine::IsExiting()
{
	return false;
}

void RoundaboutEngine::GameLoop(void)
{

}

int main()
{
	RoundaboutEngine::Initialize();
	RoundaboutEngine::Start();

	return 0;
}

