#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <math.h>

const float air_force = 0.2;

struct RigidBodyRect
{
	sf::Vector2f position;
	sf::Vector2f size;
};

struct RigidBodyCircle
{
	sf::Vector2f position = {0.0f, 0.0f};
	float radius = 0.0f;

	sf::Vector2f speed;
	float elasticity = 0.0f; // 0 - stop when collide, 1 - dense

	void update(float ts)
	{
		speed.y -= (air_force * ts);
		speed.x -= (air_force * ts);
		position.x += speed.x * ts;
		position.y += speed.y * ts;
	}

	void collide(RigidBodyRect& rect)
	{
		{
			sf::Vector2f compare_pos = { position.x , position.y };
			if (position.x < rect.position.x) // left
			{
				compare_pos.x = rect.position.x;
			}
			else if (position.x > rect.position.x + rect.size.x) // right
			{
				compare_pos.x = rect.position.x + rect.size.x;
			}

			if (position.y < rect.position.y) // top
			{
				compare_pos.x = rect.position.y;
			}
			else if (position.y > rect.position.y + rect.size.y) // left
			{
				compare_pos.x = rect.position.x + rect.size.y;
			}
			const float comp_dist = std::sqrt(std::pow(compare_pos.x - position.x, 2) + std::pow(compare_pos.y - position.y, 2));

			if (comp_dist > radius)
			{
				return;
			}
		}

		const sf::Vector2f rect_center = { rect.position.x + rect.size.x / 2 , rect.position.y + rect.size.y / 2 };
		const float dist = std::sqrt(std::pow(rect_center.x - position.x, 2) + std::pow(rect_center.y - position.y, 2));
		
		float scale = 1;

		float x_mod = 1, y_mod = 1;
		if (position.x < rect.position.x)
		{
			x_mod = -1;
		}
		if (position.y < rect.position.y)
		{
			y_mod = -1;
		}

		position.x += x_mod * scale * speed.x;
		position.y += y_mod * scale * speed.y;

		if (x_mod < 0)
		{
			speed.x *= -1;
		}

		if (y_mod < 0)
		{
			speed.y *= -1;
		}
		
	}
};

