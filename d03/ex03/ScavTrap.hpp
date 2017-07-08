#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>

class ScavTrap : public ClapTrap {

public:

	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	ScavTrap	&operator=(ScavTrap const &rhs);

	void		challengeNewcomer(std::string const &target);

private:

	void		_snipe(std::string const &target);
	void		_knifeAttack(std::string const &target);
	void		_swordFight(std::string const &target);
	void		_intimidate(std::string const &target);
	void		_taunt(std::string const &target);

};

#endif
