#pragma once

class RoundaboutEngine
{
protected:
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

public:
	sf::RenderWindow _mainWindow;

	bool IsExiting();
	void Start();
	void Initialize();
	void GameLoop(sf::Time DeltaTime);

	class Scene* MainScene;

	typedef unsigned __int64 DWORDLONG;
	typedef unsigned long DWORD;

	bool CheckStorage(DWORDLONG diskSpaceNeeded);
	DWORD ReadCPUSpeed();
	bool CheckMemory(DWORDLONG physicalRAMNeeded, DWORDLONG virtualRAMNeeded);
};

