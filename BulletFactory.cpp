/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletFactory.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:50:15 by alkozma           #+#    #+#             */
/*   Updated: 2020/01/19 18:48:38 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BulletFactory.hpp"
#include <curses.h>
#include <ncurses.h>

BulletFactory::BulletFactory()
{
	amt = 0;
	dir = 0;
}

BulletFactory::~BulletFactory()
{
	for (int i = 0; i != amt; i++)
		delete bullets[i];
}

BulletFactory::BulletFactory(const BulletFactory &x)
{
	for (int i = 0; i != 256; i++)
		bullets[i] = x.bullets[i];
}

BulletFactory&	BulletFactory::operator=(BulletFactory &x)
{
	if (this != &x)
		for (int i = 0; i != 256; i++)
			bullets[i] = x.bullets[i];
	return (*this);
}

void			BulletFactory::addBullet(int y, int x)
{
	if (amt > 255)
		return ;
	bullets[amt++] = new Bullet(y, x);
}

int				BulletFactory::getDir(void) { return (dir); }
void			BulletFactory::setDir(int n) { dir = n; }

void			BulletFactory::advanceBullets(int max_y)
{
	int	new_amt;
	int	res;

	new_amt = amt;
	for (int i = 0; i != amt; i++)
	{
		if ((res = bullets[i]->advance(this->getDir()) <= 0) || bullets[i]->getYB() >= max_y)
		{
			delete bullets[i];
			new_amt--;
		}
		else if (new_amt != amt)
			bullets[i - (amt - new_amt)] = bullets[i];
	}
	amt = new_amt;
}

void			BulletFactory::bulletPrinter(Windo win)
{
	for (int i = 0; i != amt; i++)
	{
		wattron(win.getWin(), COLOR_PAIR(dir ? 4 : 1));
		mvwprintw(win.getWin(), bullets[i]->getYB(), bullets[i]->getXB(),
				bullets[i]->getStrB().c_str());
		wattroff(win.getWin(), COLOR_PAIR(dir ? 4 : 1));
	}
}

void			BulletFactory::setAmt(int n) {
	amt = n;
}

int				BulletFactory::getAmt() {
	return (amt);
}

Bullet**		BulletFactory::getBullets() {
	return (bullets);
}

void			BulletFactory::deleteBullet(int a, int b) {
	Bullet *tmp = bullets[a];
	bullets[a] = bullets[b];
	bullets[b] = tmp;
	delete tmp;
}
