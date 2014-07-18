#ifndef SMALLCUBE_H
#define SMALLCUBE_H

#include "Cube.h"

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class SmallCube : public Cube
{
public:
						SmallCube(b2World& world, const sf::Color color, const float x, const float y);

	void				update(sf::Time dt) override;
	void				render(sf::RenderWindow& window) override;

private:
	

};

#endif