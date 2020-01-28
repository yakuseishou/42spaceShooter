/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:29:36 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/18 22:20:53 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classHPP/window.hpp"
#include <ncurses.h>

Windo::Windo(int y, int x, int yS, int xS) {
	int	ax;
	int	ay;

	if (!x || !y)
	{
		// x and y parameters are deprecated, feel free to remove
	}
	getmaxyx(stdscr, ax, ay);
    _win = newwin(ax,ay,yS,xS);
    getyx(stdscr, _y, _x);
    getbegyx(_win, _yBeg, _xBeg);
    getmaxyx(_win, _yMax, _xMax);
    _Bcount = 0;
}

Windo::~Windo() {}

Windo::Windo(Windo& other) {
    *this = other;
}

Windo&  Windo::operator=(Windo& other) {
    if (this != &other) {
        this->_win = other._win;
        this->_y = other._y;
        this->_x = other._x;
        this->_yBeg = other._yBeg;
        this->_xBeg = other._xBeg;
        this->_yMax = other._yMax;
        this->_xMax = other._xMax;
        // this->_Fi =     other._Fi;
        this->_Bcount = other._Bcount;
    }
    return (*this);
}

WINDOW* Windo::getWin() {
    return (_win);
}

int     Windo::getY() {
    return (_y);
}

int     Windo::getX() {
    return (_x);
}

int     Windo::getYBeg() {
    return (_yBeg);
}

int     Windo::getXBeg() {
    return (_xBeg);
}

int     Windo::getYMax() {
    return (_yMax);
}

int     Windo::getXMax() {
    return (_xMax);
}

// Fighter*    Windo::getFighter() {
//     return (_Fi);
// }

int         Windo::getBcount() {
    return (_Bcount);
}

// void        Windo::setFighter(Fighter* Fi) {
//     _Fi = Fi;
// }
