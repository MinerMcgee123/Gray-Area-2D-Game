#pragma once

#include "../Physics/Physics.h"

class Controls
{
private:
	const int maxChar = 14;

public:
	bool w;
	bool a;
	bool s;
	bool d;
	bool space;
	bool esc;

	bool typing;

	float mousePosX;
	float mousePosY;

	float mouseChunkX;
	float mouseChunkY;

	char letterPressed;
	bool keyToggle;

	std::string playerString;

	sf::Vector2i mousePos;

	bool leftClick;
	bool leftClickToggle;
	bool rightClick;

	Controls();
	~Controls();

	//void TypingVar(int stringSize, bool start);
	void Update(sf::Event &event);
};