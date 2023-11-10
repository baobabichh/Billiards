#include "TestScene.h"
#include "Game.h"
#include "Resources.h"

#include "MainScene.h"

TestScene::TestScene()
{
	m_text = createText();
	m_text.setString("TestScene");
}

void TestScene::update()
{
	m_shape.setFillColor(sf::Color::Blue);
	m_shape.setRadius(100);
	m_shape.setPosition({ 100,100 });

	for (const auto &e : Game::getInstance().getEvents())
	{
		if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Key::Num1)
		{
			Game::getInstance().getSceneManager().changeScene(std::make_unique<MainScene>());
		}
	}
}

void TestScene::draw() const
{
	Game::getInstance().getWindow().draw(m_shape);
	Game::getInstance().getWindow().draw(m_text);
}
