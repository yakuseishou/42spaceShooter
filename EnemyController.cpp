/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyController.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:25:17 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 19:08:04 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classHPP/EnemyController.hpp"
#include <stdlib.h>

EnemyController::EnemyController() {
    amt = 0;
    killscore = 0;
}

EnemyController::~EnemyController() {
    for (int i = 0; i != amt; i++)
		delete enemies[i];
}

EnemyController::EnemyController(const EnemyController &x) {
	for (int i = 0; i != 256; i++)
		enemies[i] = x.enemies[i];
}

EnemyController&	EnemyController::operator=(const EnemyController &x) {
    if (this != &x) {
        amt = x.amt;
	    for (int i = 0; i != 256; i++)
		    enemies[i] = x.enemies[i];
    }
	return (*this);
}

void		        EnemyController::spawnEnemy(Windo win) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uid(1, 99999);
    int xMax = win.getXMax() - 1;
    int x = uid(gen) % xMax;
    int y = 1;
    enemies[amt++] = new Enemy(y, x);
}


void		        EnemyController::moveEnemy(Windo win) {
    int	new_amt;

	new_amt = amt;
	for (int i = 0; i != amt; i++)
	{
		if (enemies[i]->advance() >= (win.getYMax() - 1))
		{
			delete enemies[i];
			new_amt--;
		}
		else if (new_amt != amt)
			enemies[i - (amt - new_amt)] = enemies[i];
	}
	amt = new_amt;
}

void			EnemyController::EnemyPrinter(Windo win)
{
	for (int i = 0; i != amt; i++)
	{
		wattron(win.getWin(), COLOR_PAIR(2));
		enemies[i]->print(win);
		wattroff(win.getWin(), COLOR_PAIR(2));
	}
}

void			EnemyController::setAmt(int n) {
	amt = n;
}

int				EnemyController::getAmt() {
	return (amt);
}

Enemy**		    EnemyController::getEnmy() {
    return (enemies);
}

void			EnemyController::fire(Windo win)
{
	for (int i = 0; i != amt; i++)
	{
		if (rand() % 10 == 0 && enemies[i]->getX() < win.getXMax() && enemies[i]->getType() == 1)
		{
			this->getBulletFactory()->addBullet(enemies[i]->getY() + 1,
					enemies[i]->getX());
		}
	}
}

BulletFactory	*EnemyController::getBulletFactory(void) { return (factory); }
void			EnemyController::setBulletFactory(BulletFactory *x) { factory = x; }

void			EnemyController::deleteEnemy(int a, int b) {
	Enemy *tmp = enemies[a];
	enemies[a] = enemies[b];
	enemies[b] = tmp;
    killscore += 10;
	delete tmp;
}

int			EnemyController::getKiScore() {
    return (killscore);
}
