#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

#include <iostream>

class NinjaTrap : public ClapTrap {

public:

	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const &src);
	~NinjaTrap(void);

	NinjaTrap	&operator=(NinjaTrap const &rhs);

	void		ninjaShoeBox(NinjaTrap const &rhs) const;
	void		ninjaShoeBox(ScavTrap const &rhs) const;
	void		ninjaShoeBox(FragTrap const &rhs) const;

};

#endif
