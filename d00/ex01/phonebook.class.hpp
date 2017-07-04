#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "contact.class.hpp"

class Phonebook {

public:

	const int	maxContacts;

	Phonebook( void );
	~Phonebook( void );

	static int	getNbInst( void );
	void		getContact( int index ) const;
	void		getAllContacts( void ) const;
	void 		addContact( void );

private:

	int			_contactCount;
	static int	_nbInst;
	Contact		_contacts[8];

};

#endif
