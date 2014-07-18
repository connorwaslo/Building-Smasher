#include "Block.h"

const float Block::SmallCubeSize = 20.0f;
const float Block::MediumCubeSize = 35.0f;
const float Block::LargeCubeSize = 50.0f;

const float Block::TallRectWidth = 20.0f;
const float Block::TallRectHeight = 60.0f;

const float Block::FlatRectWidth = 60.0f;
const float Block::FlatRectHeight = 20.0f;

Block::Block(ID id_, const float width_, const float height_)
	: id(id_)
	, width(width_)
	, height(height_)
{
}

void Block::setVelocity(const float angle_)
{
	body->SetAngularVelocity(angle_);
}

void Block::setFixtureStats(const float density_, const float friction_, const float restitution_)
{
	fixDef.density = density_;
	fixDef.friction = friction_;
	fixDef.restitution = restitution_;
}

float Block::getWidth() const
{
	return width;
}

float Block::getHeight() const
{
	return height;
}