#ifndef PONY_HPP
# define PONY_HPP

class Pony {

public:

	Pony(void);
	~Pony(void);

	int				getPonyId(void);
	int				getAge(void) const;
	std::string 	getSize(void) const;
	void			growPony(int age);

private:

	static int		_nbPony;
	int				_ponyId;
	int				_age;
	std::string		_size;

};

#endif
