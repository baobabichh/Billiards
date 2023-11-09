#include "GameStartScene.h"

#include "Game.h"

#include "MainScene.h"

GameStartScene::GameStartScene()
{
	m_text = createText();
	m_text.setString("Billiard");
	m_text.setCharacterSize(50);
	auto w_size = Game::getInstance().getWindow().getSize();
	{
		auto bounds = m_text.getGlobalBounds();
		m_text.setOrigin(bounds.width / 2, bounds.height / 2);
	}
	m_text.setPosition(w_size.x / 2, w_size.y / 2);
	
}

void GameStartScene::update()
{
	if (m_first_time_update)
	{
		m_start_clock.restart();
		m_first_time_update = false;
	}
	if (m_start_clock.getElapsedTime().asSeconds() >= m_min_loading_screen_time)
	{
		Game::getInstance().getSceneManager().changeScene(std::make_unique<MainScene>());
		return;
	}
}

void GameStartScene::draw()
{
	Game::getInstance().getWindow().draw(m_text);
}
