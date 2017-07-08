#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>

class FragTrap : public ClapTrap {

public:

	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	FragTrap	&operator=(FragTrap const &rhs);

	void		vaulthunter_dot_exe(std::string const &target);

private:

	void		_rangedAttack(std::string const &target);
	void		_meleeAttack(std::string const &target);
	void		_explosiveAttack(std::string const &target);
	void		_spinningRangedAttack(std::string const &target);
	void		_spinningMeleeAttack(std::string const &target);
	void		_spinningExplosiveAttack(std::string const &target);
	void		_cries(std::string const &target);

};

#endif
