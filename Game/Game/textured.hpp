#include "object.hpp"

class Textured : public virtual GameObject {
private:
	std::string _textureFile;
	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	Textured() {}

	sf::Sprite getSprite()
	{
		return _sprite;
	}

	void loadSprite()
	{
		if (_texture.loadFromFile(_textureFile))
		{
			_sprite.setTexture(_texture);
		}
		else {
			_texture.create(GameObject::width(), GameObject::height());
			_sprite.setTexture(_texture);
		}
		_sprite.setPosition(GameObject::x(), GameObject::y());
	}

	void setTextureFilepath(std::string filepath)
	{
		_textureFile = filepath;
	}

protected:
	void setSpritePosition(float x, float y)
	{
		_sprite.setPosition(x, y);
	}
};
