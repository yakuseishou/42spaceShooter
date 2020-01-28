/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityManager.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:26:48 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 20:39:58 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classHPP/EntityManager.hpp"
#include "prototype.hpp"
#include <ctime>
#include <string>

EntityManager::EntityManager() {

}

EntityManager::~EntityManager() {
    delete factory;
    delete econtrol;
    delete fighter;
}

EntityManager::EntityManager(const EntityManager &x) {
    fighter = x.fighter;
    for (int i = 0; i != 256; i++) {
	    factory[i] = x.factory[i];
        econtrol[i] = x.econtrol[i];
    }
    // map_x = x.map_x;
    // map_y = x.map_y;
}

EntityManager&	EntityManager::operator=(const EntityManager &x) {
    if (this != &x) {
        fighter = x.fighter;
        for (int i = 0; i != 256; i++) {
	        factory[i] = x.factory[i];
            econtrol[i] = x.econtrol[i];
        }
        // map_x = x.map_x;
        // map_y = x.map_y;
    }
    return (*this);
}

// void			EntityManager::tick() {

// }

BulletFactory*	EntityManager::getBulletFactory() {
    return (factory);
}

Fighter*		EntityManager::getFighter() {
    return (fighter);
}

EnemyController*	EntityManager::getEnemyController() {
    return (econtrol);
}

// int				EntityManager::getMapX() {
//     return (map_x);
// }

// int				EntityManager::getMapY() {
//     return (map_y);
// }

void			EntityManager::setBulletFactory(BulletFactory *x) {
    factory = x;
}

void			EntityManager::setFighter(Fighter *x) {
    fighter = x;
}

void			EntityManager::setEnemyController(EnemyController *x) {
    econtrol = x;
}

// void			EntityManager::setMapX(int n) {

// }

// void			EntityManager::setMapY(int n) {
    
// }

// void				EntityManager::FighterKO() {

// }

void				EntityManager::EnemyKO() {
	int	new_amtB = 0;
    int new_amtE = 0;
    int flag = 0;
    Enemy** en = econtrol->getEnmy();
    Bullet** blt = factory->getBullets();
	new_amtB = factory->getAmt();
	for (int i = 0; i < new_amtB; i++) {
        new_amtE = econtrol->getAmt();
        for (int j = 0; j < new_amtE;j++) {
			if (en[j]->collides(blt[i]->getYB(), blt[i]->getXB())) {
                econtrol->deleteEnemy(j , new_amtE - 1);
                new_amtE--;
                econtrol->setAmt(new_amtE);
                flag = 1;
                j--;
            }
        }
        if (flag == 1) {
            factory->deleteBullet(i , new_amtB - 1);
            new_amtB--;
	        factory->setAmt(new_amtB);
            flag = 0;
            i--;
        }
	}
}

bool			EntityManager::PlayerKO() {
    Enemy** en = econtrol->getEnmy();
	Bullet	**bulls = econtrol->getBulletFactory()->getBullets();
	int		px;
	int		py;

	px = fighter->getX();
	py = fighter->getY();
    for (int i = 0; i < econtrol->getAmt(); i++) {
		if (en[i]->collides(fighter->getY(), fighter->getX()) ||
				en[i]->collides(fighter->getY(), fighter->getX() + 1) ||
				en[i]->collides(fighter->getY(), fighter->getX() + 2))
			return (true);
    }
	for (int i = 0; i < econtrol->getBulletFactory()->getAmt(); i++)
	{
		if (bulls[i]->getXB() >= px &&
			   bulls[i]->getXB() <= px + 2 && bulls[i]->getYB() == py)
			return (true);
	}
    return (false);
}

void				EntityManager::printInfo(Windo	win) {
    int     x = this->econtrol->getKiScore();
    tPlay = (clock() - tInit) / 10000;
    std::string s = "   TIME: ";
    s += std::to_string(tPlay);
    s += "  SCORE: ";
    s += std::to_string(x);

    mvwprintw(win.getWin(), 1, 1, s.c_str());

}

int					EntityManager::getTInit() {
    return (tInit);
}
void				EntityManager::setTInit(int n) {
    tInit = n;
}

int					EntityManager::getTPlay() {
    return (tPlay);
}

void				EntityManager::setTPlay(int n) {
    tPlay = n;
}
