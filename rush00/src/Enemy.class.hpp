#ifndef ENEMYCLASS_H
# define ENEMYCLASS_H

#include "Actor.class.hpp"

class Enemy : public Actor
{
	public:
		Enemy(Vector pos, Vector const size, std::string const *sprite);
		Enemy(Enemy const &target);
		virtual ~Enemy(void);
		Enemy &operator=(Enemy const &target);

		void tick(void);

	protected:
		uint16_t _move_countdown;
};

#endif
