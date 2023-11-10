#include "MainScene.h"
#include "Game.h"

#include "Resources.h"

#include "TestScene.h"

MainScene::MainScene()
{
	m_text = createText();
	m_text.setString("MainScene");
}

void MainScene::update()
{
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setSize({ 200, 200 });
	m_shape.setPosition({ 100,100 });

	for (const auto& e : Game::getInstance().getEvents())
	{
		if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Key::Num1)
		{
			Game::getInstance().getSceneManager().changeScene(std::make_unique<TestScene>());
		}
	}
}

void MainScene::draw() const
{
	Game::getInstance().getWindow().draw(m_shape);
	Game::getInstance().getWindow().draw(m_text);
}
