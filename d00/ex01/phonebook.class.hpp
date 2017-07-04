#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

class Phonebook {

public:

	int			foo;
	int			publicFoo;
	char		a1;
	int			a2;
	float		a3;
	float const pi;
	int			pd;

	Phonebook( char p1, int p2, float p3 , float const f );
	~Phonebook( void );

	void		bar( void ) const;
	void		publicBar( void ) const;
	int			getPrivateFoo( void ) const;
	void		setPrivateFoo( int val );
	int			compare( Phonebook * other ) const;
	static int	getNbInst( void );

private:

	int			_privateFoo;
	static int	_nbInst;

	void		_privateBar( void ) const;

};

#endif
