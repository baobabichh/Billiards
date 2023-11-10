#pragma once

#include "Scene.h"

class MainScene : public Scene
{
public:
	MainScene();
	void update() override;
	void draw()const override;

private:
	sf::RectangleShape m_shape{};
	sf::Text m_text{};
};