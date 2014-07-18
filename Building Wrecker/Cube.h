#ifndef CUBE_H
#define CUBE_H

#include "Block.h"

class Cube : public Block
{
public:
						Cube(Block::ID id_, const float size);
	virtual void		update(sf::Time dt) = 0;
	virtual void		render(sf::RenderWindow& window) = 0;

	void				setWorld(b2World& world);

	float				getSize() const;

protected:
	

private:
	float				size;

};

#endif