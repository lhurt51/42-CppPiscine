#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Game.class.hpp"

Game::Game(void) : _window(initscr()) {
	cbreak();
	noecho();
	clear();
	refresh();
	keypad(this->_window, true);
	nodelay(this->_window, true);
	curs_set(0);
	if(!has_colors()) {
        printf("ERROR: Terminal does not support color.\n");
        this->~Game();
		return;
    }
	start_color();
	attron(A_BOLD);
    box(this->_window, 0, 0);
    attroff(A_BOLD);
	init_pair(1, COLOR_BLACK, COLOR_CYAN);
    wbkgd(this->_window, COLOR_PAIR(1));
	return;
}

Game::Game(Game const &src) {
	*this = src;
	return;
}

Game::~Game(void) {
	endwin();
	return;
}

Game	&Game::operator=(Game const &rhs) {
	if (this != &rhs) {
		this->_window = rhs.getWindow();
		this->_maxX = rhs.getMaxX();
		this->_maxY = rhs.getMaxY();
	}
	return *this;
}

void	Game::run(void) {
	static size_t i = 0;

	move(5, 5);
    std::string text = "Hello world!";

    while(1) {
		getmaxyx(stdscr, this->_maxY, this->_maxX);
		if (i < text.size()) {
			addch(text[i++]);
			addch(' ');
		}

		sleep(1);
	    refresh();
	}
}

WINDOW*	Game::getWindow(void) const {
	return this->_window;
}

int		Game::getMaxX(void) const {
	return this->_maxX;
}

int		Game::getMaxY(void) const {
	return this->_maxY;
}
