#include <map>
#include <SFML/Graphics.hpp>

class MyTextureManager {
private:
	std::map<std::string, sf::Texture> _texturesMap;

public:
	sf::Texture getTexture(std::string object) 
	{
		return _texturesMap[object];
	}

	void addTexture(std::string object, std::string texturePath)
	{
		sf::Texture texture;
		texture.loadFromFile(texturePath);
		_texturesMap[object] = texture;
	}
};
