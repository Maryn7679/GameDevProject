#include <SFML/Graphics.hpp>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <iostream>
#include "player.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Game!", sf::Style::Close);
    Player player(250.f, 250.f);

    sf::Event event;
    bool isActive = true;

    while (window.isOpen())
    {
        // read
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::LostFocus)
                isActive = false;
            if (event.type == sf::Event::GainedFocus)
                isActive = true;
        }

        // update
        if (isActive) {
            player.getAcceleration();

            player.updatePosition(window);

            // render
            window.clear();
            window.draw(player.object());
            window.display();
        }
    }

    return 0;
}
