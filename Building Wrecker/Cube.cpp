#include "Cube.h"

Cube::Cube(Block::ID id_, const float size_)
	: Block(id_, size_, size_)
	, size(size_)
{
}

void Cube::setWorld(b2World& world)
{
	body = world.CreateBody(&bodyDef);
	body->CreateFixture(&fixDef);
}

float Cube::getSize() const
{
	return size;
}