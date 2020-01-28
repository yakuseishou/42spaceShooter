/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseUnit.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:20:18 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/18 18:22:32 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classHPP/BaseUnit.hpp"

BaseUnit::BaseUnit() : 
    _s(""), _y(0), _x(0) {
		srand(time(NULL));
}

BaseUnit::BaseUnit(int y, int x) :
    _s(""), _y(y), _x(x) {
}

BaseUnit::~BaseUnit() {}

BaseUnit::BaseUnit(BaseUnit& other) {
    *this = other;
}

BaseUnit&    BaseUnit::operator=(BaseUnit& other) {
    if (this != &other) {
        this->_s = other._s;
        this->_y = other._y;
        this->_x = other._x;
    }
    return (*this);
}

std::string BaseUnit::getStr() {
    return (_s);
}

int         BaseUnit::getY() {
    return (_y);
}

int         BaseUnit::getX() {
    return (_x);
}

void             BaseUnit::setStr(std::string s) {
    _s = s;
}

void            BaseUnit::setY(int n) {
    _y = n;
}

void            BaseUnit::setX(int n) {
    _x = n;
}

void			BaseUnit::genPos(int max_y, int max_x)
{
	this->setX(rand() % max_x);
	this->setY(rand() % max_y);
}
