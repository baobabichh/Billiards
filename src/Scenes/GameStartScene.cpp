#include "GameStartScene.h"

#include "Game.h"

#include "MainScene.h"

GameStartScene::GameStartScene()
{
	Resources::getInstance().minLoad();

	const auto w_size = Game::getInstance().getWindow().getSize();

	{
		m_image.setTexture(Resources::getInstance().getTexture("billiard_start"));
		auto bounds = m_image.getLocalBounds();
		float min_scale = std::max((float)w_size.x / bounds.width, (float)w_size.y / bounds.height);
		m_image.setScale(min_scale, min_scale);
		center(m_image, w_size);
	}
	
	{
		m_text = createText();
		m_text.setString("Billiard");
		m_text.setCharacterSize(100);
		center(m_text, w_size);
	}


	{
		m_text_loading = createText();
		m_text_loading.setString("Loading");
		m_text_loading.setCharacterSize(50);
		center(m_text_loading, w_size);
		m_text_loading.move(0, 100);
	}
}

void GameStartScene::update()
{
	if (m_first_time_update)
	{
		m_first_time_update = false;
		m_worker = std::thread(&GameStartScene::loadFunction, this);
		m_timer.restart();
		m_worker.detach();
	}

	if (m_timer.getElapsedTime().asSeconds() >= m_time_per_dot)
	{
		m_timer.restart();
		m_dot_count++;
		m_dot_count %= (m_max_dot_count + 1);
		std::string res{};
		res = "Loading";
		for (size_t i = 0; i < m_dot_count; i++)
		{
			res += ".";
		}

		m_text_loading.setString(res);
	}

	if (m_tasks_done)
	{
		Game::getInstance().getSceneManager().changeScene(std::make_unique<MainScene>());
		return;
	}
}

void GameStartScene::draw() const
{
	Game::getInstance().getWindow().draw(m_image);
	Game::getInstance().getWindow().draw(m_text);
	Game::getInstance().getWindow().draw(m_text_loading);
}

void GameStartScene::loadFunction()
{
	Resources::getInstance().load();

	// std::this_thread::sleep_for(std::chrono::seconds(5))

	m_tasks_done = true;
}
