#ifndef APP_H
#define APP_H

#include "Barrier.h"
#include "SmallCube.h"

#include <SFML/Graphics.hpp>
#include <Box2D/Common/b2Math.h> 
#include <Box2D/Dynamics/b2World.h>

class App final
{
public:
						App();
	void				run();

	void				handleInput();
	void				update(sf::Time dt);
	void				render();

	static const sf::Time TimePerFrame;
	static const unsigned Width = 800;
	static const unsigned Height = 600;

private:
	sf::RenderWindow	window;
	sf::View			camera;

	b2Vec2				gravity;
	b2World				world;

	float32				timeStep;
	int32				velocityIterations;
	int32				positionIterations;

	SmallCube			box;
	SmallCube			box2;

	Barrier				ground;
	Barrier				leftWall;
	Barrier				rightWall;
	Barrier				roof;

};

#endif