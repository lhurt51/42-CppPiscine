#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {

private:

	std::string _name;
	std::string _instType;
	static std::string _type;

	void		_setInstType(void);

public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void		anounce(void) const;
	std::string	getName(void) const;
	std::string getInstType(void) const;
	static std::string getType(void);
	static void	setType(std::string type);
};

#endif
