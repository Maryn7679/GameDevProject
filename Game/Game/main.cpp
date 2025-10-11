#include <SFML/Graphics.hpp>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <iostream>
#include "player.cpp"

int main()
{
    //glm::vec3 v(2.f, 2.f, 2.f);
    //float l = glm::length(v);
    //std::cout << l;

    sf::RenderWindow window(sf::VideoMode(500, 500), "Game!");
    //sf::RectangleShape shape(sf::Vector2(20.f, 20.f));
    //shape.setFillColor(sf::Color::Green);

    Player player(250.f, 250.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        player.update(window);
        //std::cout << "x: " << player.object().getPosition().x << ", y: " << player.object().getPosition().x;
        //std::cout << "x: " << player.getVelocity().x << ", y: " << player.getVelocity().y;
        window.draw(player.object());
        window.display();
    }

    return 0;
}
