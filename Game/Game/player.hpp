#include <SFML/Graphics.hpp>
#include <glm/vec2.hpp>
#include <iostream>
#include "TextureManager.hpp"

class Player {
private:
    std::string _textureFile = "textures/player.png";
    sf::Sprite _sprite;
    sf::RectangleShape _hitbox;
    sf::Texture _texture;

    glm::vec2 _velocity;
    glm::vec2 _acceleration;
    static constexpr float _accelerationCoef = 0.5f;
    static constexpr float _resistanceCoef = 0.95f;

    float _x;
    float _y;

public:
    Player(float x, float y) {
        if (_texture.loadFromFile(_textureFile))
        {
            _hitbox.setFillColor(sf::Color(200, 0, 111));
            _sprite.setTexture(_texture);
        }
        else {
            _hitbox.setFillColor(sf::Color(0, 200, 111));
        }
        _sprite.setPosition({ x, y });

        _hitbox.setSize(sf::Vector2(20.f, 20.f));
        _hitbox.setPosition({ x, y });

        _velocity = glm::vec2(0.f, 0.f);
        _acceleration = glm::vec2(0.f, 0.f);

        _x = x;
        _y = y;
    }

    sf::RectangleShape getHitbox() {
        return _hitbox;
    }

    sf::Sprite getSprite() {
        return _sprite;
    }

    glm::vec2 getVelocity() {
        return _velocity;
    }

    glm::vec2 getAcceleration() {
        return _acceleration;
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
        _sprite.setPosition(_x, _y);
    };
};