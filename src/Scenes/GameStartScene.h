#pragma once

#include "Scene.h"

#include <chrono>
#include <thread>
#include <atomic>

class GameStartScene : public Scene
{
public:
	GameStartScene();
	void update() override;
	void draw()const override;

private:
	sf::Sprite m_image{};
	sf::Text m_text{};
	sf::Text m_text_loading{};

	sf::Clock m_timer{};
	unsigned char m_dot_count = 0;
	const unsigned char m_max_dot_count = 3;
	const float m_time_per_dot = 0.5f;

	bool m_first_time_update = true;

	std::thread m_worker{};
	std::atomic_bool m_tasks_done = false;

	void loadFunction();
};