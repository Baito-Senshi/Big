#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "RoundaboutEngine.h"
#include "SplashScreen.h"

int main()
{
	RoundaboutEngine engine;

	engine.Initialize();
	engine.Start();

	return 0;
} 