
#include "Define.h"
#include "json.hpp"
#include "21_Clock.h"
#include "20_Physics.h"
#include "10_Menu.h"
#include "03_Player.h"
#include "40_Textures.h"

int main(int argc, char *argv[])
{
	enum GameState { EXIT, MENU };
	GameState gameState;
	gameState = MENU;

	int count = 0;

	// create window
	sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Gray Area", sf::Style::Fullscreen, sf::ContextSettings(24,8,4));
	//-->1920/1080 ratio is 16/9

	// event handler
	sf::Event event;

	Textures textures;

	Chunk chunk;

	Controls controls;

	Menu menu;

	Player player(&textures);

	Physics physics;

	Clock clock;

	//Game Loop
	while (window.isOpen()) {
		window.clear();

		clock.Update(textures);

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		controls.mousePosX = mousePos.x;
		controls.mousePosY = mousePos.y;

		while (window.pollEvent(event))
		{
			controls.Update(event);

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		//Left Click Updater
		if (event.type == sf::Event::EventType::MouseButtonPressed
			&& controls.leftClickToggle == true)
		{
			controls.leftClick = true;
			controls.leftClickToggle = false;
		}
		else
		{
			controls.leftClick = false;
		}

		if (event.type == sf::Event::EventType::MouseButtonReleased
			&& controls.leftClickToggle == false)
		{
			controls.leftClickToggle = true;
		}

		//Menu Page Loader
		switch (gameState)
		{
		case MENU:
			menu.Draw(&clock, &controls, &chunk, &player, &textures, window);
			break;
		}

		//FPS COUNTER
		clock.Draw(window);
		
		window.display();

	}

	return 0;
}