#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

class HumanB {

public:

	HumanB(std::string const name);
	~HumanB(void);

	void	attack(void) const;
	void	setWeapon(Weapon &weapon);

private:

	std::string const	_name;
	Weapon				*_weapon;

};

#endif
