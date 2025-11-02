#include "object.hpp"

class Movable : public virtual GameObject {
private:
	glm::vec2 _velocity = glm::vec2(0.f, 0.f);
	glm::vec2 _acceleration = glm::vec2(0.f, 0.f);
	float _accelerationCoef;
	float _resistanceCoef;

public:
	Movable() {}

	glm::vec2 getVelocity() {
		return _velocity;
	}

	glm::vec2 getAcceleration() {
		return _acceleration;
	}

	void setAcceleration(float acceleration)
	{
		_accelerationCoef = acceleration;
	}

	void setResistance(float resistance)
	{
		_resistanceCoef = resistance;
	}

	void updatePosition(sf::RenderWindow& window, glm::vec2 direction) {
		_acceleration = direction * _accelerationCoef;
		_velocity += _acceleration;

		_x += _velocity.x;
		_y += _velocity.y;

		_velocity = _resistanceCoef * _velocity;
		if (_velocity.length() < 0.01f)
		{
			_velocity = glm::vec2(0.f, 0.f);
		}

		if (_x < 0) {
			_x = window.getSize().x;
		}
		if (_y < 0) {
			_y = window.getSize().y;
		}
		if (_x > window.getSize().x) {
			_x = 0;
		}
		if (_y > window.getSize().y) {
			_y = 0;
		}

		_hitbox.setPosition(_x, _y);
	};
};
