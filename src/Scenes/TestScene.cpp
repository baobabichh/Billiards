#include "TestScene.h"
#include "Game.h"
#include "Resources.h"

#include "MainScene.h"

#include <iostream>

TestScene::TestScene()
{
	m_ball.setFillColor(sf::Color::Blue);


	{
		m_ball_body.position = { 200, 200 };
		m_ball_body.radius = 30;
		m_ball.setRadius(m_ball_body.radius);
		m_ball.setPosition(m_ball_body.position);
	}

	{
		m_left_rect.position = { 0,0 };
		m_left_rect.size = { 50,400 };

		m_left.setPosition(m_left_rect.position);
		m_left.setSize(m_left_rect.size);
	}

	{
		m_right_rect.position = { 400,0 };
		m_right_rect.size = { 50,400 };

		m_right.setPosition(m_right_rect.position);
		m_right.setSize(m_right_rect.size);
	}

	{
		m_top_rect.position = { 0,0 };
		m_top_rect.size = { 400,50 };

		m_top.setPosition(m_top_rect.position);
		m_top.setSize(m_top_rect.size);
	}

	{
		m_down_rect.position = { 0,400 };
		m_down_rect.size = { 400,50 };

		m_down.setPosition(m_down_rect.position);
		m_down.setSize(m_down_rect.size);
	}
}

void TestScene::update()
{
	std::cout << m_ball_body.position.x << " " << m_ball_body.position.y << "\n";
	for (const auto& e : Game::getInstance().getEvents())
	{
		if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Key::Num1)
		{
			Game::getInstance().getSceneManager().changeScene(std::make_unique<MainScene>());
		}
		else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Key::Left)
		{
			m_ball_body.speed.x = -100;
		}
		else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Key::Right)
		{
			m_ball_body.speed.x = 100;
		}
		else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Key::Up)
		{
			m_ball_body.speed.y = -100;
		}
		else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Key::Down)
		{
			m_ball_body.speed.y = 100;
		}
	}

	float ts = Game::getInstance().getTimeStep();
	m_ball_body.update(ts);

	m_ball_body.collide(m_left_rect);
	m_ball_body.collide(m_right_rect);
	m_ball_body.collide(m_top_rect);
	m_ball_body.collide(m_down_rect);

	{
		m_ball.setRadius(m_ball_body.radius);
		m_ball.setPosition(m_ball_body.position);
	}

	{
		m_left.setPosition(m_left_rect.position);
		m_left.setSize(m_left_rect.size);
	}

	{
		m_right.setPosition(m_right_rect.position);
		m_right.setSize(m_right_rect.size);
	}

	{
		m_top.setPosition(m_top_rect.position);
		m_top.setSize(m_top_rect.size);
	}

	{
		m_down.setPosition(m_down_rect.position);
		m_down.setSize(m_down_rect.size);
	}
}

void TestScene::draw() const
{
	Game::getInstance().getWindow().draw(m_left);
	Game::getInstance().getWindow().draw(m_right);
	Game::getInstance().getWindow().draw(m_top);
	Game::getInstance().getWindow().draw(m_down);
	Game::getInstance().getWindow().draw(m_ball);
}
