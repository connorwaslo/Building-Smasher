#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Block
{
public:
	enum ID
	{
		SmallCube,
		LargeCube,
		TallRect,
		FlatRect,
		None
	};

						Block(ID id_, const float width_, const float height_);
	virtual void		update(sf::Time dt) = 0;
	virtual void		render(sf::RenderWindow& window) = 0;

	void				setVelocity(const float angle_);
	void				setFixtureStats(const float density_, const float friction_, const float restitution_);

	float				getWidth() const;
	float				getHeight() const;

protected:
	static const float	SmallCubeSize;
	static const float  MediumCubeSize;
	static const float  LargeCubeSize;
	static const float	TallRectWidth;
	static const float	TallRectHeight;
	static const float	FlatRectWidth;
	static const float	FlatRectHeight;

	float				density;
	float				friction;
	float				restitution;

	sf::Color			color;

	b2Body*				body;
	b2BodyDef			bodyDef;
	b2FixtureDef		fixDef;
	b2PolygonShape		polyShape;
	sf::RectangleShape	rectShape;

private:
	ID					id;
	float				width;
	float				height;
};

#endif