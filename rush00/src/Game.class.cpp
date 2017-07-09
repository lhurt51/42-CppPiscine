#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Vector.class.hpp"
#include "Actor.class.hpp"
#include "Game.class.hpp"

int		Game::_maxWinX = 500;
int		Game::_maxWinY = 500;

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
	}
	return *this;
}

void	Game::run(void) {
	Actor	player(Vector(10, 5), Vector(1, 1), '0');
	int		inChar;
	bool 	exit_requested = false;

    while(1) {
        inChar = wgetch(this->_window);

		mvaddch(player.getPos().getY(), player.getPos().getX(), ' ');

        switch(inChar) {
            case 'q':
                exit_requested = true;
                break;
            case KEY_UP:
            case 'w':
                player.move(Vector(0, -1));
                break;
            case KEY_DOWN:
            case 's':
                player.move(Vector(0, 1));
                break;
            case KEY_LEFT:
            case 'a':
                player.move(Vector(-1, 0));
                break;
            case KEY_RIGHT:
            case 'd':
                player.move(Vector(1, 0));
                break;
            default:
                break;
        }

		mvaddch(player.getPos().getY(), player.getPos().getX(), player.getSprite());
        refresh();

        if(exit_requested) break;

		usleep(10000);
	}
}

WINDOW*	Game::getWindow(void) const {
	return this->_window;
}

int		Game::getWinMaxX(void) {
	return Game::_maxWinX;
}

int		Game::getWinMaxY(void) {
	return Game::_maxWinY;
}
