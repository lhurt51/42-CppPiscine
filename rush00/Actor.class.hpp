#ifndef ACTOR_CLASS_HPP
# define ACTOR_CLASS_HPP

# include <iostream>

class Actor {

public:

	Actor(void);
	Actor(Actor const &src);
	~Actor(void);

	Actor	&operator=(Actor const &rhs);

	Vector	getPos(void) const;
	Vector	getSize(void) const;
	bool	getCollision(void) const;
	char const getSprite(void) const;
	void	setPos(Vector &pos);
	void	move(Vector &pos);
	bool	bDoesCollide(Actor *src) const;
	virtual void	tick(void);


private:

	Vector			_pos;
	Vector const	_size;
	char const		**sprite;
	bool			_collide;

};

#endif
