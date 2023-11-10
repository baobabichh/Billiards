#pragma once
#include "Events.h"
#include "SceneManager.h"
#include "Debug.h"

class Game
{
public:
	static Game& getInstance();
	void run();

	const Events& getEvents()const;
	sf::RenderWindow& getWindow();
	float getTimeStep()const;
	SceneManager& getSceneManager();

private:
	Game() = default;

	void update();
	void draw();

	void load();
	void createWindow();


private:
	sf::RenderWindow m_window{};
	Events m_events{};
	SceneManager m_scene_manager{};
	DebugLayer m_debug_layer{};
	float m_time_step{};
};

