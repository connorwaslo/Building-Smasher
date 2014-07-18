#ifndef BARRIER_H
#define BARRIER_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Barrier
{
public:
						Barrier(b2World& world, float x, float y, float width, float height);
	void				update(sf::Time dt);
	void				render(sf::RenderWindow& window);

private:
	b2Body*				body;
	b2BodyDef			bodyDef;
	b2FixtureDef		fixDef;
	b2PolygonShape		polyShape;
	sf::RectangleShape	rectShape;
};

#endif