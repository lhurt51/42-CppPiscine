#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap {

public:

	ClapTrap(std::string name, unsigned int maxHp, unsigned int maxEp, unsigned int meleeDamage, unsigned int rangedDamage, unsigned int armor);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);

	ClapTrap		&operator=(ClapTrap const &rhs);

	std::string		getName(void) const;
	unsigned int	getHp(void) const;
	unsigned int	getEp(void) const;
	unsigned int	getLevel(void) const;
	unsigned int	getMaxHp(void) const;
	unsigned int	getMaxEp(void) const;
	unsigned int	getMeleeDamage(void) const;
	unsigned int	getRangedDamage(void) const;
	unsigned int	getArmor(void) const;
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

protected:

	std::string			_name;
	unsigned int		_hp;
	unsigned int		_ep;
	unsigned int		_level;
	const unsigned int	_maxHp;
	const unsigned int	_maxEp;
	const unsigned int	_meleeDamage;
	const unsigned int	_rangedDamage;
	const unsigned int	_armor;

};

#endif
