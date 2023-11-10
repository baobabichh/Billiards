#include "Debug.h"

#include "Game.h"

#include <sstream>
#include <iomanip>

DebugLayer::DebugLayer()
{
	m_fps_text = createText();
}

void DebugLayer::update()
{
	
	for (const auto& e : Game::getInstance().getEvents())
	{
		if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Key::F1)
		{
			m_show_fps = !m_show_fps;
		}
	}

	if (m_show_fps)
	{
		float ts = Game::getInstance().getTimeStep();
		unsigned int fps = 1.0f / ts;
		m_fps_text.setString(std::to_string(fps));
	}
}

void DebugLayer::draw() const
{
	if (m_show_fps)
	{
		Game::getInstance().getWindow().draw(m_fps_text);
	}
}
