#include <SFML/Graphics.hpp>
#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

class myPlayer {
public:
	myPlayer(int, int);
	sf::RectangleShape object();
	void update(sf::RenderWindow&);
};

#endif