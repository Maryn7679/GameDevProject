#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.hpp"
#include "functions.hpp"

int main()
{
    Functions functions;
    //MyTextureManager textureManager;
    //textureManager.addTexture("player", "textures/player.png");
    sf::RenderWindow window(sf::VideoMode(500, 500), "Game!", sf::Style::Close);
    Player player(250.f, 250.f);

    sf::Event event;
    bool isActive = true;

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
                glm::vec2 direction = functions.getInputDirection();

                //update
                player.updatePosition(window, direction);
                //std::cout << "x:" << direction.x << " y:" << direction.y;
                std::cout << "x:" << player.getVelocity().x << " y:" << player.getVelocity().y;
                //std::cout << "x:" << player.getAcceleration().x << " y:" << player.getAcceleration().y;

                // render
                window.clear();
                window.draw(player.getSprite());
                window.display();
            }
        }
    }

    return 0;
}
