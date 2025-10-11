#include <SFML/Graphics.hpp>
#include <glm/vec2.hpp>

class Player {
public:
    Player(float x, float y) {
        _playerObject.setSize(sf::Vector2(20.f, 20.f));
        _velocity = glm::vec2(0.f, 0.f);
        _playerObject.setFillColor(sf::Color::Green);
        _playerObject.setPosition({ x, y });
        _x = x;
        _y = y;
    }

    sf::RectangleShape object() {
        return _playerObject;
    }

    glm::vec2 getVelocity() {
        return _velocity;
    }

    void update(sf::RenderWindow& window) {
        glm::vec2 acceleration = glm::vec2(0.f, 0.f);

        const float dAcc = 0.3f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            acceleration.y -= dAcc;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            acceleration.x -= dAcc;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            acceleration.y += dAcc;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            acceleration.x += dAcc;

        _velocity += acceleration;

        _x += _velocity.x;
        _y += _velocity.y;
        //_x += acceleration.x;
        //_y += acceleration.y;

        _velocity = 0.5f * _velocity;
        if (_velocity.length() < 0.01f)
        {
            _velocity = glm::vec2(0.f, 0.f);
        }

        _playerObject.setPosition(_x, _y);

        window.draw(_playerObject);
    };
private:
    sf::RectangleShape _playerObject;
    glm::vec2 _velocity;
    float _x;
    float _y;

};