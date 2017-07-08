#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>

class ScavTrap {

public:

	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	ScavTrap	&operator=(ScavTrap const &rhs);

	std::string	getName(void) const;
	int			getHp(void) const;
	int			getEp(void) const;
	int			getLevel(void) const;
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		challengeNewcomer(std::string const &target);

private:

	std::string			_name;
	int					_hp;
	int					_ep;
	int					_level;
	static int const	_maxHp;
	static int const	_maxEp;
	static int const	_meleeDamage;
	static int const	_rangedDamage;
	static int const	_armor;

	void		_snipe(std::string const &target);
	void		_knifeAttack(std::string const &target);
	void		_swordFight(std::string const &target);
	void		_intimidate(std::string const &target);
	void		_taunt(std::string const &target);

};

#endif
