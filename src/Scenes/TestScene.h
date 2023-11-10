#pragma once

#include "Scene.h"
#include "Phisics/RigidBodyRect.h"

class TestScene : public Scene
{
public:
	TestScene();
	void update() override;
	void draw()const override;

private:
	sf::RectangleShape m_left, m_right, m_top, m_down;
	sf::CircleShape m_ball;

	RigidBodyCircle m_ball_body{};
	RigidBodyRect m_left_rect, m_right_rect, m_top_rect, m_down_rect;

};