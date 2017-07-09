#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP

# include <iostream>

class Vector {

public:

	Vector(void);
	Vector(int x, int y);
	Vector(Vector const &src);
	~Vector(void);

	Vector	&operator=(Vector const &rhs);
	Vector	operator+(Vector const &rhs) const;
	Vector	operator-(Vector const &rhs) const;
	Vector	operator*(Vector const &rhs) const;
	Vector	operator/(Vector const &rhs) const;
	bool	operator==(Vector const &rhs) const;
	bool	operator!=(Vector const &rhs) const;

	int		getX(void) const;
	int		getY(void) const;
	void	setX(int x);
	void	setY(int y);

private:

	uint16_t	_x;
	uint16_t	_y;

};

std::ostream	&operator<<(std::ostream &o, Vector const &i);

#endif
