#include "Events.h"
void Events::pool(sf::RenderWindow& window)
{
	clear();
	sf::Event event{};
	while (window.pollEvent(event))
	{
		m_events.push_back(event);
	}
}

void Events::clear()
{
	m_events.clear();
}
std::vector<sf::Event>::const_iterator Events::begin() const
{
	return m_events.begin();
}

std::vector<sf::Event>::const_iterator Events::end() const
{
	return m_events.end();
}

std::vector<sf::Event>::iterator Events::begin()
{
	return std::begin(m_events);
}

std::vector<sf::Event>::iterator Events::end()
{
	return std::end(m_events);
}
