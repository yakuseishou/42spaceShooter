/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fighter.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:18:26 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 09:02:14 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classHPP/Fighter.hpp"
#include "classHPP/BaseUnit.hpp"
// #include "classHPP/window.hpp"

Fighter::Fighter() {}

Fighter::Fighter(int yMax, int xMax) : BaseUnit(yMax, xMax) {
    this->setStr("<|>");
    this->setY(yMax - 2);
    this->setX(xMax / 2);
}

Fighter::~Fighter() {}

Fighter::Fighter(Fighter& other) {
    *this = other;
}

Fighter&    Fighter::operator=(Fighter& other) {
    if (this != &other) {
        this->setStr(other._s);
        this->setY(other._y);
        this->setX(other._x);
    }
    return (*this);
}

void    Fighter::movFiLeft() {
    if ((this->getX() - 1) > 2)
        this->setX(this->getX() - 1);
}

void    Fighter::movFiRight(Windo win) {
    if ((this->getX() + 1) < (win.getXMax() - 4))
        this->setX(this->getX() + 1);
}

void    Fighter::movFiUp() {
    if ((this->getY() - 1) > 2)
        this->setY(this->getY() - 1);
}

void    Fighter::movFiDown(Windo win) {
    if ((this->getY() + 1) < (win.getYMax() - 2))
        this->setY(this->getY() + 1);
}

void    Fighter::prinFigher(Windo win) {
	wattron(win.getWin(), COLOR_PAIR(3));
    mvwprintw(win.getWin(), this->getY(), this->getX(), this->getStr().c_str());
	wattroff(win.getWin(), COLOR_PAIR(3));
}

void    Fighter::shootBullet(BulletFactory *b) {
		if ((this->getY() - 1) > 2) {
			b->addBullet(this->getY() - 1, this->getX());
            b->addBullet(this->getY() - 1, this->getX() + 2);
		}
}
