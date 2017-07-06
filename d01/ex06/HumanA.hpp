#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

class HumanA {

public:

	HumanA(std::string const name, Weapon &weapon);
	~HumanA(void);

	void	attack(void) const;

private:

	std::string const	_name;
	Weapon				&_weapon;

};

#endif
