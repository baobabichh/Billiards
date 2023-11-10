#pragma once

#include "Scene.h"

class TestScene : public Scene
{
public:
	TestScene();
	void update() override;
	void draw()const override;

private:
	sf::CircleShape m_shape{};
	sf::Text m_text{};

};