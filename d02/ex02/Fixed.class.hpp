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
	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator+(Fixed const &rhs) const;
	Fixed	operator-(Fixed const &rhs) const;
	Fixed	operator*(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;
	bool	operator>(Fixed const &rhs) const;
	bool	operator<(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator==(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed		&max(Fixed &val1, Fixed &val2);
	static Fixed const	&max(Fixed const &val1, Fixed const &val2);
	static Fixed		&min(Fixed &val1, Fixed &val2);
	static Fixed const	&min(Fixed const &val1, Fixed const &val2);


private:

	int 				_val;
	static const int	_fractBits;

};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
