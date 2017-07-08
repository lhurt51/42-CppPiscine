#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>

class FragTrap {

public:

	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	FragTrap	&operator=(FragTrap const &rhs);

	std::string	getName(void) const;
	int			getHp(void) const;
	int			getEp(void) const;
	int			getLevel(void) const;
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		vaulthunter_dot_exe(std::string const &target);

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

	void		_rangedAttack(std::string const &target);
	void		_meleeAttack(std::string const &target);
	void		_explosiveAttack(std::string const &target);
	void		_spinningRangedAttack(std::string const &target);
	void		_spinningMeleeAttack(std::string const &target);
	void		_spinningExplosiveAttack(std::string const &target);
	void		_cries(std::string const &target);

};

#endif
