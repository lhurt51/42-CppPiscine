#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP

# include <iostream>

class Vector {

public:

	Vector(void);
	Vector(uint16_t x, uint16_t y);
	Vector(Vector const &src);
	~Vector(void);

	Vector	&operator=(Vector const &rhs);
	Vector	operator+(Vector const &rhs) const;
	Vector	operator-(Vector const &rhs) const;
	Vector	operator*(Vector const &rhs) const;
	Vector	operator/(Vector const &rhs) const;
	bool	operator==(Vector const &rhs) const;
	bool	operator!=(Vector const &rhs) const;

	uint16_t		getX(void) const;
	uint16_t		getY(void) const;
	void			setX(uint16_t x);
	void			setY(uint16_t y);

private:

	uint16_t	_x;
	uint16_t	_y;

};

std::ostream	&operator<<(std::ostream &o, Vector const &i);

#endif
