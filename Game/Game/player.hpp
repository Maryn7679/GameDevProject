#include "textured.hpp"
#include "movable.hpp"

class Player : public Textured, public Movable {
private:
public:
	Player() {}

	void updatePosition(sf::RenderWindow& window, glm::vec2 direction)
	{
		Movable::updatePosition(window, direction);
		Textured::setSpritePosition(GameObject::x(), GameObject::y());
	}

	static glm::vec2 getInputDirection() {
		glm::vec2 direction = glm::vec2(0, 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			direction.y = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			direction.x = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			direction.y = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			direction.x = 1;

		return direction;
	};
};
