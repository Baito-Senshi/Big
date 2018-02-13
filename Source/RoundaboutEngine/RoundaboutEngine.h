#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class RoundaboutEngine
{
public:
	RoundaboutEngine();
	static void Start();
	static void Initialize();

	static void GameLoop();
	static bool IsExiting();

	static sf::RenderWindow _mainWindow;

	enum GameState {
		Uninitialized,
		Initialized,
		ShowingSplash,
		ShowingMenu,
		Playing,
		Paused,
		Exiting
	};
	static GameState _gameState;

private:
};

