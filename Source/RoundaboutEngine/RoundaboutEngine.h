#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class RoundaboutEngine
{
public:
	void Start();
	void Initialize();
	void GameLoop();
	bool IsExiting();

	sf::RenderWindow _mainWindow;

	enum GameState {
		Uninitialized,
		Initialized,
		ShowingSplash,
		ShowingMenu,
		Playing,
		Paused,
		Exiting
	};

	GameState _gameState;

private:


};

