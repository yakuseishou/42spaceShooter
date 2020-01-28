/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnBulFactory.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:43:12 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 03:49:23 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnBulFactory.hpp"
#include <curses.h>

EnBulFactory::EnBulFactory()
{
	amt = 0;
}

EnBulFactory::~EnBulFactory()
{
	for (int i = 0; i != amt; i++)
		delete bullets[i];
}

EnBulFactory::EnBulFactory(const EnBulFactory &x)
{
	for (int i = 0; i != 256; i++)
		bullets[i] = x.bullets[i];
}

EnBulFactory&	EnBulFactory::operator=(EnBulFactory &x)
{
	if (this != &x)
		for (int i = 0; i != 256; i++)
			bullets[i] = x.bullets[i];
	return (*this);
}

void			EnBulFactory::addBullet(int y, int x)
{
	bullets[amt++] = new EnBullet(y, x);
}

void			EnBulFactory::advanceBullets(void)
{
	int	new_amt;

	new_amt = amt;
	for (int i = 0; i != amt; i++)
	{
		if (bullets[i]->advance() <= 0)
		{
			delete bullets[i];
			new_amt--;
		}
		else if (new_amt != amt)
			bullets[i - (amt - new_amt)] = bullets[i];
	}
	amt = new_amt;
}

void			EnBulFactory::bulletPrinter(Windo win)
{
	for (int i = 0; i != amt; i++)
	{
		mvwprintw(win.getWin(), bullets[i]->getYB(), bullets[i]->getXB(),
				bullets[i]->getStrB().c_str());
	}
}

void			EnBulFactory::setAmt(int n) {
	amt = n;
}

int				EnBulFactory::getAmt() {
	return (amt);
}

EnBullet**		EnBulFactory::getBullets() {
	return (bullets);
}

// void			EnBulFactory::deleteBullet(int a, int b) {
// 	EnBullet *tmp = bullets[a];
// 	bullets[a] = bullets[b];
// 	bullets[b] = tmp;
// 	delete tmp;
// }