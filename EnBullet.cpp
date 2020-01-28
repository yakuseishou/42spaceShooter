/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnBullet.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:45:14 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 03:45:57 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classHPP/Bullet.hpp"

Bullet::Bullet(int yF, int xF) {
    _B = 'v';
    _yB = yF;
    _xB = xF;
}

Bullet::~Bullet() {

}

Bullet::Bullet(Bullet& other) {
    *this = other;
}

Bullet&         Bullet::operator=(Bullet& other) {
    if (this != &other) {
        this->_B =  other._B;
        this->_yB = other._yB;
        this->_xB = other._xB;
    }
    return (*this);
}

std::string     Bullet::getStrB() const {
    return (_B);
}

int             Bullet::getYB() {
    return (_yB);
}

int             Bullet::getXB() {
    return (_xB);
}

void            Bullet::setYB(int n) {
    _yB = n;
}

void            Bullet::setXB(int n) {
    _xB = n;
}

int				Bullet::advance(void) {
	return ((_yB += 2));
}