#pragma once

#include "Scene.h"

class DebugLayer
{
public:
	DebugLayer();
	void update();
	void draw()const;
private:
	sf::Text m_fps_text{};
	bool m_show_fps = false;

};
