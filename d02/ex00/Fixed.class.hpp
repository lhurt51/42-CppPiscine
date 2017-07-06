#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {

public:
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed	&operator=(Fixed const &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);


private:

	int 				_val;
	static const int	_fractBits;

};


#endif
