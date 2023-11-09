#pragma once
#include "Events.h"
#include "SceneManager.h"

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
	Game();

	void update();
	void draw();

	void createWindow();

private:
	sf::RenderWindow m_window{};
	Events m_events{};
	SceneManager m_scene_manager{};
	float m_time_step{};
};

