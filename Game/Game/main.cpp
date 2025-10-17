#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.cpp"
#include "functions.cpp"

int main()
{
    Functions functions;
    sf::RenderWindow window(sf::VideoMode(500, 500), "Game!", sf::Style::Close);
    Player player(250.f, 250.f);

    sf::Event event;
    bool isActive = true;

    while (window.isOpen())
    {
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

            // render
            window.clear();
            window.draw(player.object());
            window.display();
        }
    }

    return 0;
}
