/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:50:43 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 19:21:58 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classHPP/Enemy.hpp"
#include "classHPP/BaseUnit.hpp"
#include "classHPP/window.hpp"

Enemy::Enemy() {}

void	Enemy::setType(int new_type) { type = new_type; }
void	Enemy::setLife(int new_life) { life = new_life; }
void	Enemy::setDir(int new_dir) { dir = new_dir; }
int		Enemy::getDir(void) { return (dir); }
int		Enemy::getLife(void) { return (life); }
int		Enemy::getType(void) { return (type); }

Enemy::Enemy(int y, int x) : BaseUnit(y, x) {
    this->setStr("@");
    this->setY(1);
    this->setX(x);
	this->setType(rand() % 5);
	this->setLife(0);
	this->setDir(0);
}

Enemy::~Enemy() {}

Enemy::Enemy(Enemy& other) {
    *this = other;
}

Enemy&    Enemy::operator=(Enemy& other) {
    if (this != &other) {
        this->setStr(other._s);
        this->setY(other._y);
        this->setX(other._x);
    }
    return (*this);
}

int				Enemy::meteorMove(void)
{
	return ((_y += 1));
}

int				Enemy::zigZagMove(void)
{
	_y = (_x <= 1 ? 10 : 10 + (_x % 3));
	if (this->getDir() == 0)
	{
		if (_x <= 0)
		{
			this->setDir(1);
			_x = 1;
			return (_y);
		}
		else
		{
			--_x;
			return (_y);
		}
	}
	else
	{
		++_x;
		return (_y);
	}
}

int				Enemy::advance(void) {
	this->setLife(this->getLife() + 1);
	switch (this->getType())
	{
		case 1:
			return (this->zigZagMove());
		default:
			return (this->meteorMove());
	}
	return (0);
}

void			Enemy::print(Windo win)
{
	switch(this->getType())
	{
		case 2:
			mvwprintw(win.getWin(), this->getY(), this->getX(), "@@");
			mvwprintw(win.getWin(), this->getY() + 1, this->getX(), "@@");
			break ;
		default:
			mvwprintw(win.getWin(), this->getY(), this->getX(), "@");
			break ;
	}
}

int				Enemy::collides(int y, int x)
{
	if (this->getType() == 2)
	{
		if ((this->getY() == y || this->getY() + 1 == y) &&
				(this->getX() == x || this->getX() + 1 == x))
			return (1);
	}
	else
	{
		if (this->getY() == y && this->getX() == x)
			return (1);
		return (0);
	}
	return (0);
}
