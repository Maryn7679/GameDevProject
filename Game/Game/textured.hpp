#include "object.hpp"

class Textured : public virtual GameObject {
private:
	std::string _textureFile;
	sf::Sprite _sprite;
	sf::Texture _texture;

public:
	Textured() {}

	void loadTexture()
	{
		if (_texture.loadFromFile(_textureFile))
		{
			_sprite.setTexture(_texture);
		}
		else {
			_texture.create(GameObject::width(), GameObject::height());
			_sprite.setTexture(_texture);
		}
	}

	sf::Sprite getSprite()
	{
		return _sprite;
	}

	void setTextureFilepath(std::string filepath)
	{
		_textureFile = filepath;
	}

	void setSpritePosition(float x, float y)
	{
		_sprite.setPosition(x, y);
	}
};
