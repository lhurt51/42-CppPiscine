#ifndef PROJECTILE_CLASS_HPP
# define PROJECTILE_CLASS_HPP

# include <iostream>

class Projectile : public Actor {

public:

	Projectile(Vector pos);
	Projectile(Projectile const &src);
	virtual	~Projectile(void);

	Projectile	&operator=(Projectile const &rhs);

	void		tick(void);

private:

	uint16_t		_moveSpeed;

	void		_checkPos(void);
	void		_updatePos(void);

};

#endif
