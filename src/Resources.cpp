#include "Resources.h"
#include <iostream>
#include <cassert>


Resources& Resources::getInstance()
{
	static Resources s{};
	return s;
}

void Resources::load()
{
	loadFont("resources/Montserrat-Regular.ttf", "montserrat");
}

void Resources::minLoad()
{
	loadFont("resources/From Cartoon Blocks.ttf", "default_font");
	loadTexture("resources/billiard_start.jpg", "billiard_start");
}

void Resources::loadFont(const std::string& fname, const std::string& name)
{
	sf::Font font;
	bool loaded = false;
	for (size_t i = 0; i < 5; i++)
	{
		if (font.loadFromFile(fname))
		{
			loaded = true;
			break;
		}
		else
		{
			loaded = false;
		}
	}

	if (loaded)
	{
		m_fonts[name] = std::move(font);
	}
}

void Resources::loadTexture(const std::string& fname, const std::string& name)
{
	sf::Texture texture;
	bool loaded = false;
	for (size_t i = 0; i < 5; i++)
	{
		if (texture.loadFromFile(fname))
		{
			loaded = true;
			break;
		}
		else
		{
			loaded = false;
		}
	}

	if (loaded)
	{
		m_textures[name] = std::move(texture);
	}
}

const sf::Font& Resources::getFont(const std::string& name) const
{
	const auto f = m_fonts.find(name);
	if (std::cend(m_fonts) == f)
	{
		std::cout << "Failed to load font " << name << "\n";
		assert(0);
	}

	return f->second;
}

const sf::Texture& Resources::getTexture(const std::string& name) const
{
	const auto f = m_textures.find(name);
	if (std::cend(m_textures) == f)
	{
		std::cout << "Failed to load texure " << name << "\n";
		assert(0);
	}

	return f->second;
}

Resources::Resources()
{
	load();
}

sf::Text createText()
{
	sf::Text text{};

	// select the font
	text.setFont(::Resources::getInstance().getFont("montserrat")); // font is a sf::Font

	// set the character size
	text.setCharacterSize(30); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::White);

	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);

	return text;
}

