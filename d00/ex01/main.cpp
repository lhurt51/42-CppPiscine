#include "main.hpp"
#include "phonebook.class.hpp"

int		main() {
	std::cout << "getNbInst() = " << Phonebook::getNbInst() << std::endl;
	Phonebook newBook( 'a', 42, 4.2f, 3.14f );
	std::cout << "getNbInst() = " << Phonebook::getNbInst() << std::endl;
	Phonebook newBook1( 'b', 21, 1.4f, 2.43f );
	std::cout << "getNbInst() = " << Phonebook::getNbInst() << std::endl;
	newBook.foo = 42;
	newBook.bar();
	newBook.publicFoo = 42;
	std::cout << "1 this->publicFoo: " << newBook.publicFoo << std::endl;
	newBook.publicBar();
	newBook.setPrivateFoo( 42 );
	newBook1.setPrivateFoo( 42 );
	std::cout << "1 getPrivateFoo() = " << newBook.getPrivateFoo() << std::endl;
	std::cout << "2 getPrivateFoo() = " << newBook1.getPrivateFoo() << std::endl;
	newBook.setPrivateFoo( -42 );
	newBook1.setPrivateFoo( -42 );
	std::cout << "1 getPrivateFoo() = " << newBook.getPrivateFoo() << std::endl;
	std::cout << "2 getPrivateFoo() = " << newBook1.getPrivateFoo() << std::endl;

	if (&newBook == &newBook)
		std::cout << "book and book are physically equal " << std::endl;
	else
		std::cout << "book and book are not physically equal " << std::endl;

	if (&newBook == &newBook1)
		std::cout << "book and book1 are physically equal " << std::endl;
	else
		std::cout << "book and book1 are not physically equal " << std::endl;

	if (newBook.compare( &newBook ) == 0)
		std::cout << "book and book are structurally equal " << std::endl;
	else
		std::cout << "book and book are not structurally equal " << std::endl;

	if (newBook.compare( &newBook1 ) == 0)
		std::cout << "book and book1 are structurally equal " << std::endl;
	else
		std::cout << "book and book1 are not structurally equal " << std::endl;

	Phonebook	instance( 'c', 12, 5.6f, 1.34f );
	Phonebook	*instancep = &instance;

	int			Phonebook::*p = NULL;
	void		(Phonebook::*f)(void) const;

	p = &Phonebook::foo;

	std::cout << "Foo = " << instance.foo << std::endl;
	instance.*p = 21;
	std::cout << "Foo = " << instance.foo << std::endl;
	instancep->*p = 42;
	std::cout << "Foo = " << instance.foo << std::endl;

	f = &Phonebook::bar;

	(instance.*f)();
	(instancep->*f)();

	return 0;
}
