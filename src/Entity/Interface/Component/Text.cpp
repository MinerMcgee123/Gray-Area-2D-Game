
#include "Component.h"

void Component::Text(sf::RenderWindow& window)
{
	text.setFillColor(sf::Color(textColorRef[0], textColorRef[1], textColorRef[2], textColorRef[3]));
	sf::Rect<float> size = text.getGlobalBounds();
	text.setOrigin(sf::Vector2f(size.width / 2, size.height / 2 + 10));
	text.setPosition(sf::Vector2f(position[0], position[1]));
}