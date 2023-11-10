#include "Functions.h"

void center(sf::Text& text, sf::Vector2u size)
{
	auto bounds = text.getLocalBounds();
	text.setOrigin(bounds.width / 2, bounds.height / 2);
	text.setPosition(size.x / 2, size.y / 2);
}

void center(sf::Sprite& sp, sf::Vector2u size)
{
	auto bounds = sp.getLocalBounds();
	sp.setOrigin(bounds.width / 2, bounds.height / 2);
	sp.setPosition(size.x / 2, size.y / 2);
}
