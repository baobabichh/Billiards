#pragma once

#include "Scene.h"

#include <chrono>

class GameStartScene : public Scene
{
public:
	GameStartScene();
	void update() override;
	void draw()const override;

private:
	sf::Text m_text{};
	sf::Clock m_start_clock{};
	const float m_min_loading_screen_time = 5.0f;

	bool m_first_time_update = true;
};