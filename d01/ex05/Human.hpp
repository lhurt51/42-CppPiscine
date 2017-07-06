#ifndef HUMAN_HPP
# define HUMAN_HPP

class Human {

public:

	Human(void);
	~Human(void);

	std::string identify(void) const;
	const Brain &getBrain(void) const;

private:

	Brain const _brain;


};

#endif
