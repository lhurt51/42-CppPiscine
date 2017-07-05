#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

class ZombieHorde {

private:

	int	const					_nbZombies;
	Zombie *					_zombieHorde;
	static std::string const	_names[];
	static std::string const	_types[];

public:

	ZombieHorde(int n);
	~ZombieHorde(void);

	void						announce(void);

};

#endif
