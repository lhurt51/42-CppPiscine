#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {

public:
	Fixed(void);
	Fixed(int const val);
	Fixed(float const val);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed	&operator=(Fixed const &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;


private:

	int 				_val;
	static const int	_fractBits;

};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
