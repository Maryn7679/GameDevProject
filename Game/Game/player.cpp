#include <SFML/Graphics.hpp>
#include <glm/vec2.hpp>

class Player {
private:
    sf::RectangleShape _playerObject;
    glm::vec2 _velocity;
    glm::vec2 _acceleration;
    const float _dAcc = 0.3f;
    float _x;
    float _y;

public:
    Player(float x, float y) {
        _playerObject.setSize(sf::Vector2(20.f, 20.f));
        _velocity = glm::vec2(0.f, 0.f);
        _acceleration = glm::vec2(0.f, 0.f);
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

    //void getAcceleration() {
    //    _acceleration = glm::vec2(0.f, 0.f);

    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    //        _acceleration.y -= _dAcc;
    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    //        _acceleration.x -= _dAcc;
    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    //        _acceleration.y += _dAcc;
    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    //        _acceleration.x += _dAcc;
    //}

    void updatePosition(sf::RenderWindow& window, glm::vec2 direction) {
        _acceleration = direction * _dAcc;
        _velocity += _acceleration;

        _x += _velocity.x;
        _y += _velocity.y;

        _velocity = 0.5f * _velocity;
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

        _playerObject.setPosition(_x, _y);
    };
};