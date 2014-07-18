#include "Barrier.h"

const float PPM = 100.0f;

Barrier::Barrier(b2World& world, float x, float y, float width, float height)
{
	bodyDef.position.Set(x / PPM, y / PPM);
	bodyDef.type = b2_staticBody;

	rectShape.setSize(sf::Vector2f(width, height));
	rectShape.setOrigin(width / 2, height / 2);
	rectShape.setFillColor(sf::Color::Black);

	polyShape.SetAsBox((width / 2) / PPM, (height / 2) / PPM);
	body = world.CreateBody(&bodyDef);

	fixDef.shape = &polyShape;
	fixDef.density = 1.0f;
	fixDef.friction = 0.8f;

	body->CreateFixture(&fixDef);
}

void Barrier::update(sf::Time dt)
{
	rectShape.setPosition(body->GetPosition().x * PPM, body->GetPosition().y * PPM);
	rectShape.setRotation(body->GetAngle() * 180 / b2_pi);
}

void Barrier::render(sf::RenderWindow& window)
{
	window.draw(rectShape);
}