#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

# include "Projectile.class.hpp"

class Character : public Actor {

public:

	Character(WINDOW *window);
	Character(Character const &src);
	virtual ~Character(void);

	Character	&operator=(Character const &rhs);

	int			getInChar(void) const;
	bool		getExitRequest(void) const;
	void		tick(void);
	Projectile	*fire(void);

private:

	WINDOW		*_window;
	int			_inChar;
	bool		_bExitRequested;
	bool		_bIsFiring;

	void		_checkPos(void);
	void		_handleUserInput(void);
	void		_hasCollided(void);

	static Vector const _start_location;
};

#endif
