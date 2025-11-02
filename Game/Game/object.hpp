#include <SFML/Graphics.hpp>
#include <glm/vec2.hpp>
#ifndef __OBJECT_HPP_INCLUDED__   // if x.h hasn't been included yet...
#define __OBJECT_HPP_INCLUDED__

class GameObject {
private:
	sf::RectangleShape _hitbox;

	float _width;
	float _height;

	float _x;
	float _y;

public:
	GameObject() 
	{
		_hitbox.setFillColor(sf::Color(0, 0, 0, 0));
		_hitbox.setOutlineThickness(1.f);
		_hitbox.setOutlineColor(sf::Color(250, 0, 250));
	}

	float x() { return _x; }
	float y() { return _y; }

	float width() { return _width; }
	float height() { return _height; }

	sf::RectangleShape getHitbox() {
		return _hitbox;
	}

	void setSize(float width, float height) 
	{
		_hitbox.setSize(sf::Vector2(width, height));
	}

	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }

	void setPosition(float x, float y)
	{
		_hitbox.setPosition({ x, y });

		_x = x;
		_y = y;
	}

	friend class Movable;
};

#endif
