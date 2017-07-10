#include <iostream>
#include <string>
#include <ncurses.h>
#include "Vector.class.hpp"
#include "Actor.class.hpp"
#include "Character.class.hpp"
#include "Enemy.class.hpp"
#include "Projectile.class.hpp"
#include "Game.class.hpp"
#include "Spawn.class.hpp"
#include <typedefs.hpp>

int		Game::_maxWinX = 100;
int		Game::_maxWinY = 50;

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
	for (int i = 0; i < Game::getWinMaxX() + 1; i++)
		mvaddch(Game::getWinMaxY() + 2, i, '-');
	for (int i = 0; i < Game::getWinMaxY() + 2; i++)
		mvaddch(i, Game::getWinMaxX() + 1, '|');
	refresh();
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
	Character	player(this->_window);
	//0 is player, 1 - 11 are enemies
	Actor		*actors[1 + ENEMY_COUNT + BULLET_COUNT];
	Spawn		spawn;

	for (unsigned int i = 0; i < sizeof(actors) / sizeof(*actors); i++)
		actors[i] = NULL;
	actors[0] = &player;
    while (1) {
		//spawn enemies
		for (int i = ENEMY_OFFSET; i < ENEMY_COUNT + ENEMY_OFFSET; i++)
		{
			if (actors[i] == NULL)
			{
				actors[i] = spawn.createEnemy();
				break ;
			}
		}
		//try to add a bullet from the player
		for (unsigned int i = BULLET_OFFSET; i < BULLET_COUNT + BULLET_OFFSET; i++)
		{
			if (actors[i] == NULL) {
				actors[i] = player.fire();
				break;
			}
		}
		for (unsigned int i = 0; i < sizeof(actors) / sizeof(*actors); i++)
		{
			if (actors[i])
				actors[i]->tick();
		}
		//check for collision
		for (unsigned int i = 0; i < sizeof(actors) / sizeof(*actors); i++)
		{
			for (unsigned int j = i; j < sizeof(actors) / sizeof(*actors); j++)
			{
				if (actors[i] && actors[j] && i != j)
					actors[i]->bDoesCollide(*actors[j]);
			}
		}
		//delete actors
		for (unsigned int i = 0; i < sizeof(actors) / sizeof(*actors); i++)
		{
			if (actors[i] && actors[i]->getCollision())
			{
				delete actors[i];
				actors[i] = NULL;
			}
		}
        refresh();

        if(player.getExitRequest()) break;
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
