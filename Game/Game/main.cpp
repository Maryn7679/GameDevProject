#include <SFML/Graphics.hpp>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <iostream>

int main()
{
    glm::vec3 v(2.f, 2.f, 2.f);
    float l = glm::length(v);
    std::cout << l;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
