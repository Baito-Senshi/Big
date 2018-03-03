#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SplashScreen.h"
#include "direct.h"
#include "RoundaboutEngine.h"
#include "windows.h"
#include <iostream>

void RoundaboutEngine::Start(void)
{
	//If gamestate is not Uninitialized change it to Initialized
	if (_gameState != Uninitialized)
	{
		_gameState = Initialized;
		return;
	}

	//Draw window and change gamestate to Playing
	//_mainWindow.create(sf::VideoMode(1024, 768, 32), "Roundabout Engine");
	//sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "Roundabout Engine");
	_gameState = ShowingSplash;

	while (_gameState)
	{
		sf::Event event;
		while (_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_mainWindow.close();
		}
		_mainWindow.clear();
		_mainWindow.display();
	}
}

void RoundaboutEngine::Initialize(void)
{
	_gameState = Uninitialized;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Roundabout Engine");

	SplashScreen sc;
	sc.Show(_mainWindow);

	if (!CheckStorage(800000000) || 
		!ReadCPUSpeed() ||
		!CheckMemory(800000000, 800000000)) { return; }
	else
	{
		_gameState = ShowingSplash;
	}

	while (_gameState != Initialized) {
		sf::Event event;
		while (_mainWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}

	}
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
}
