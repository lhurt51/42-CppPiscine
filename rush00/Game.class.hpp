#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <iostream>

class Game {

public:

	Game(void);
	Game(Game const &src);
	~Game(void);

	Game	&operator=(Game const &rhs);

	void	run(void);
	WINDOW*	getWindow(void) const;
	int		getMaxX(void) const;
	int		getMaxY(void) const;

private:

	WINDOW*	_window;
	int		_maxX;
	int		_maxY;

};

#endif
