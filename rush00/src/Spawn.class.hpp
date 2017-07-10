#ifndef SPAWN_CLASS_HPP
# define SPAWN_CLASS_HPP

# include "Enemy.class.hpp"
# include <random>

class Spawn
{
	public:
		Spawn(void);
		Spawn(Spawn const &target);
		virtual ~Spawn(void);
		Spawn &operator=(Spawn const &target);

		Enemy *createEnemy(void);
		static  std::basic_string<char> const sprites[][1];

	private:
		
		std::random_device _rd;
		std::mt19937 _rng;
		std::uniform_int_distribution<int> _uni_art;
		std::uniform_int_distribution<int> _uni_start;
		uint16_t _countdown;

};

#endif
