#include "SmallCube.h"
#include "Utility.h"

SmallCube::SmallCube(b2World& world, const sf::Color color, const float x, const float y)
	: Cube(ID::SmallCube, Block::SmallCubeSize)
{
	rectShape = sf::RectangleShape(sf::Vector2f(getWidth(), getHeight()));
	rectShape.setOrigin(getWidth() / 2, getHeight() / 2);
	rectShape.setFillColor(color);

	bodyDef.position.Set(x / util::PPM, y / util::PPM);
	bodyDef.type = b2_dynamicBody;
	polyShape.SetAsBox(getWidth() / 2 / util::PPM, getHeight() / 2 / util::PPM);

	fixDef.shape = &polyShape;
}

void SmallCube::update(sf::Time dt)
{
	rectShape.setPosition(body->GetPosition().x * util::PPM, body->GetPosition().y * util::PPM);
	rectShape.setRotation(body->GetAngle() * 180 / b2_pi);
}

void SmallCube::render(sf::RenderWindow& window)
{
	window.draw(rectShape);
}