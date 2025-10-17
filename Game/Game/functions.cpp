#include <SFML/Graphics.hpp>
#include <glm/vec2.hpp>

class Functions {
public:
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