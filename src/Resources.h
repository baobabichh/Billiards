#pragma once

#include "SFML/Graphics.hpp"
#include <unordered_map>

class Resources
{
public:
	static Resources& getInstance();

	void load();
	void minLoad();

	void loadFont(const std::string& fname, const std::string& name);
	void loadTexture(const std::string& fname, const std::string& name);

	const sf::Font& getFont(const std::string& name)const;
	const sf::Texture& getTexture(const std::string& name)const;
private:
	std::unordered_map<std::string, sf::Font> m_fonts{};
	std::unordered_map<std::string, sf::Texture> m_textures{};

	Resources();
};

sf::Text createText();

