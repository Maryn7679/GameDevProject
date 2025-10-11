#include <SFML/Graphics.hpp>

class Player {
public:
    Player(float x, float y) {
        _playerObject.setSize(sf::Vector2(20.f, 20.f));
        _velocity = sf::Vector2(0.f, 0.f);
        _playerObject.setFillColor(sf::Color::Green);
        _playerObject.setPosition({ x, y });
        _x = x;
        _y = y;
    }

    sf::RectangleShape object() {
        return _playerObject;
    }

    sf::Vector2<float> getVelocity() {
        return _velocity;
    }

    void update(sf::RenderWindow& window) {
        sf::Vector2f acceleration;

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

        _velocity = 0.1f * _velocity;
        //_velocity = sf::Vector2(0.f, 0.f);

        _playerObject.setPosition(_x, _y);

        window.draw(_playerObject);
    };
private:
    sf::RectangleShape _playerObject;
    sf::Vector2<float> _velocity;
    float _x;
    float _y;

};