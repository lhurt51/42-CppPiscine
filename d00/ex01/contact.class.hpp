#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact {

public:

	Contact( void );
	~Contact( void );

	static int	getNbInst( void );
	void		showContact( void ) const;
	void		showContacts( void ) const;
	void		startFilling( void );

private:

	static int	_nbInst;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_login;
	std::string	_postalAddress;
	std::string _phoneNumber;
	std::string _birthDate;
	std::string _favoriteMeal;
	std::string _underwearColor;
	std::string _darkestSecret;

	void		_setContact( void );
	std::string	_recieveInput( std::string ) const;
	std::string	_truncateInput( std::string ) const;
};

#endif
