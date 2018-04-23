#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "direct.h"
#include "windows.h"
#include "RoundaboutEngine.h"
#include "SplashScreen.h"
#include "Scene.h"
#include "GameObject.h"
#include "TransformComponent.h"


#include <iostream>

void RoundaboutEngine::Start(void)
{
	if (_gameState != Uninitialized)
	{
		_gameState = Initialized;
	}

	MainScene = new Scene();
	GameObject* Object = new GameObject("Test");
	GameObject* Object2 = new GameObject("Child");

	//std::cout << Object->GetTransform()->GetTransform().getMatrix() << std::endl;

	Object->AddChild(Object2);

	MainScene->AddChild(Object);

	sf::Clock Clock;

	while (_gameState)
	{
		sf::Time DeltaTime = Clock.restart();
		sf::Event event;

		while (_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_mainWindow.close();
		}
		_mainWindow.clear();
		_mainWindow.display();

		GameLoop(DeltaTime);
	}
}

void RoundaboutEngine::Initialize(void)
{
	_gameState = Uninitialized;
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Roundabout Engine");
	_mainWindow.setFramerateLimit(60);

	sf::Clock Clock;
	sf::Time SplashTime = sf::seconds(3.0f);
	sf::Time SplashDuration = Clock.getElapsedTime();

	SplashScreen Splash;
	Splash.Show(_mainWindow);

	_gameState = ShowingSplash;

	if (!CheckStorage(800000000) || 
		!ReadCPUSpeed() ||
		!CheckMemory(800000000, 800000000))
	{
		_gameState = Uninitialized; 
		return;
	}
	else
	{
		while (SplashDuration < SplashTime){ SplashDuration = Clock.getElapsedTime(); }
		_gameState = Initialized;
		return;
	}
}

bool RoundaboutEngine::IsExiting()
{
	return false;
}

void RoundaboutEngine::GameLoop(sf::Time DeltaTime)
{
	_gameState = ShowingMenu;

	MainScene->Update(DeltaTime);
}

bool RoundaboutEngine::CheckStorage(DWORDLONG diskSpaceNeeded)
{
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);

	unsigned __int64 const neededClusters = diskSpaceNeeded /
		(diskfree.sectors_per_cluster*diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters)
	{
		std::cout << "CheckStorage Failure: Not enough physical storage." << std::endl;
		return false;
	}
	std::cout << "CheckStorage Success." << std::endl;
	return true;
}

DWORD RoundaboutEngine::ReadCPUSpeed()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
	}
	return dwMHz;
}

bool RoundaboutEngine::CheckMemory(DWORDLONG physicalRAMNeeded, DWORDLONG virtualRAMNeeded)
{
	MEMORYSTATUSEX status;
	GlobalMemoryStatusEx(&status);
	if (status.ullTotalPhys < physicalRAMNeeded)
	{
		std::cout << "CheckMemory Failure: Not enough physical memory." << std::endl;
		return false;
	}
	if (status.ullAvailVirtual < virtualRAMNeeded)
	{
		std::cout << "CheckMemory Failure: Not enough virtual memory." << std::endl;
		return false;
	}
	else { return true; }
}
