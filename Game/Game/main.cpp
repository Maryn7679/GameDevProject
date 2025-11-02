#include <iostream>
#include "player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Game!", sf::Style::Close);

    Player player;
    player.setSize(20.f, 20.f);
    player.setPosition(250.f, 250.f);
    player.setAcceleration(0.5f);
    player.setResistance(0.95f);
    player.setTextureFilepath("textures/player.png");
    player.loadSprite();

    Textured wall;
    wall.setSize(20.f, 116.f);
    wall.setPosition(400.f, 250.f);
    wall.setTextureFilepath("textures/wall.png");
    wall.loadSprite();

    Textured enemy;
    enemy.setSize(123.f, 116.f);
    enemy.setPosition(50.f, 250.f);
    enemy.setTextureFilepath("textures/enemy.png");
    enemy.loadSprite();

    sf::Event event;
    bool isActive = true;
    bool renderHitbox = true;

    sf::Clock clock;
    float fps = 60.f;

    while (window.isOpen())
    {
        if (clock.getElapsedTime().asSeconds() > 1 / fps)
        {
            clock.restart();

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::LostFocus)
                    isActive = false;
                if (event.type == sf::Event::GainedFocus)
                    isActive = true;
            }

            if (isActive) {
                // read
                glm::vec2 direction = player.getInputDirection();

                //update
                player.updatePosition(window, direction);
                //std::cout << " x:" << player.x() << " y:" << player.y();
                //std::cout << "x:" << player.getVelocity().x << " y:" << player.getVelocity().y;
                //std::cout << "x:" << player.getAcceleration().x << " y:" << player.getAcceleration().y;

                // render
                window.clear();
                window.draw(player.getSprite());
                window.draw(wall.getSprite());
                window.draw(enemy.getSprite());
                if (renderHitbox) 
                {
                    window.draw(player.getHitbox());
                    window.draw(wall.getHitbox());
                    window.draw(enemy.getHitbox());
                }
                window.display();
            }
        }
    }

    return 0;
}
