#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

class ZombieEvent {

private:

	static std::string const _names[];

public:

	ZombieEvent(void);
	~ZombieEvent(void);

	void	setZombieType(std::string type);
	Zombie* newZombie(std::string name);
	void	randomChump(void);

};

#endif
