#include "Game.h"

#include <memory.h>

#include "Scenes/MainScene.h"



Game& Game::getInstance()
{
	static Game s{};
	return s;
}

void Game::run()
{
    sf::Clock clock{};
    while (m_window.isOpen())
    {
        m_time_step = clock.restart().asSeconds();
        m_events.pool(m_window);

        update();

        m_window.clear();
        draw();
        m_window.display();
    }
}

const Events& Game::getEvents() const
{
    return m_events;
}

sf::RenderWindow& Game::getWindow()
{
    return m_window;
}

float Game::getTimeStep() const
{
    return m_time_step;
}

SceneManager& Game::getSceneManager()
{
    return m_scene_manager;
}

Game::Game()
{
	createWindow();
    m_scene_manager.changeScene(std::make_unique<MainScene>());
}

void Game::update()
{
    for (const auto event : m_events)
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }

    m_scene_manager.update();
}

void Game::draw()
{
    m_scene_manager.draw();
}

void Game::createWindow()
{
	m_window.create(sf::VideoMode(1080, 720), "sfml game");
}
