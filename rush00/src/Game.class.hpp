#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <iostream>

class Game {

public:

	Game(void);
	Game(Game const &src);
	~Game(void);

	Game		&operator=(Game const &rhs);

	void		run(void);
	WINDOW*		getWindow(void) const;
	static int	getWinMaxX(void);
	static int	getWinMaxY(void);

private:

	WINDOW*		_window;
	static int	_maxWinX;
	static int	_maxWinY;

};

#endif
