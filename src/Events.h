#pragma once
#include <vector>
#include "SFML/Graphics.hpp"

class Events
{
public:
	void pool(sf::RenderWindow& window);
	void clear();

	std::vector<sf::Event>::const_iterator begin()const;
	std::vector<sf::Event>::const_iterator end()const;
	std::vector<sf::Event>::iterator begin();
	std::vector<sf::Event>::iterator end();

private:
	std::vector<sf::Event> m_events{};
};
