#ifndef ACTOR_CLASS_HPP
# define ACTOR_CLASS_HPP

# include <iostream>
# include "Vector.class.hpp"

class Actor {

public:


	Actor(Vector pos, Vector const size, std::string const *sprite);
	Actor(Actor const &src);
	virtual ~Actor(void);

	Actor	&operator=(Actor const &rhs);

	Vector	getPos(void) const;
	Vector	getSize(void) const;
	bool	getCollision(void) const;
	std::string const *getSprite(void) const;
	void	setPos(Vector pos);
	void	move(Vector pos);
	bool	bDoesCollide(Actor &src);
	void	draw(void);
	void	clear(void);
	virtual void	tick(void) = 0;


protected:

	Vector			_pos;
	Vector const	_size;
	std::string const *_sprite;
	bool			_bCollide;

	virtual void	_hasCollided(void);

};

#endif
