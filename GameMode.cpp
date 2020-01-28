/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameMode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:26:41 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 20:41:25 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <ncurses.h>
#include "prototype.hpp"
#include "BulletFactory.hpp"
#include <random>
#include <time.h>

void	InGameKeyListen(Windo win, Fighter* Fi, BulletFactory *b) {
	int	c = wgetch(win.getWin());
    
	switch (c) {
        case KEY_LEFT :
            Fi->movFiLeft();
            break;
        case KEY_RIGHT :
            Fi->movFiRight(win);
            break;
        case KEY_UP :
            Fi->movFiUp();
            break;
        case KEY_DOWN :
            Fi->movFiDown(win);
            break;
        case 'q' :
            gameMenu(win);
        case 'c' :
            Fi->shootBullet(b);
        default :
            break;
        }
}

EntityManager*  InitManager(Fighter* Fi, BulletFactory *b, EnemyController *e) {
    EntityManager*  Manager = new EntityManager();
    Manager->setFighter(Fi);
    Manager->setBulletFactory(b);
    Manager->setEnemyController(e);
    return (Manager);
}

void	doStars(Windo win)
{
	static int	stars[256][256];
	static int	stars2[256][256];
	static int	init;
	int			amt;
	int			amt2;

	if (!init)
	{
		amt = rand() % ((256));
		amt2 = rand() % ((256));
		while (amt--)
			stars[rand() % 256][rand() % 256] = 1;
		while (amt2--)
			stars2[rand() % 256][rand() % 256] = 1;
		init = 1;
	}
	for (int i = 255; i >= 0; i--)
	{
		for (int n = 255; n >= 0; n--)
		{
			if (stars[i][n] == 1)
			{
				mvwprintw(win.getWin(), i, n, "*");
				stars[(i + 2) % 256][n] = stars[i][n];
				stars[i][n] = 0;
			}
			else if (stars2[i][n] == 1)
			{
				mvwprintw(win.getWin(), i, n, ".");
				stars2[(i + 1) % 256][n] = stars2[i][n];
				stars2[i][n] = 0;
			}
		}
	}
}

void    GameInit(Windo win) {
    wclear(win.getWin());
    Fighter* Fi = new Fighter(win.getYMax(), win.getXMax());
    Fi->prinFigher(win);
    createBoarder(win);
    wrefresh(win.getWin());
    keypad(win.getWin(), true);
	BulletFactory	*b = new BulletFactory();
    EnemyController *e = new EnemyController();
	e->setBulletFactory(new BulletFactory());
	e->getBulletFactory()->setDir(1);
    EntityManager*  Manager = InitManager(Fi, b, e);
    Manager->setTInit(clock());
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLUE);
	init_pair(2, COLOR_YELLOW, COLOR_RED);
	init_pair(3, COLOR_RED, COLOR_WHITE);
	init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    // halfdelay(1); //wait 5 sec then -1 if no input
    nodelay(win.getWin(), true);
    // wtimeout(win.getWin(), 10); //wait 5 sec then -1 if no input
	float elapsed = 0.0;
	int t = clock();
    while (1) {
		elapsed += (((float)clock() - (float)t)/CLOCKS_PER_SEC);
		t = clock();
        if (elapsed >= 0.015) {
			elapsed = 0;
        	InGameKeyListen(win, Fi, b);
            //if (Manager->PlayerKO())
                //gameOver(win, Manager);
			wclear(win.getWin());
			doStars(win);
			b->advanceBullets(win.getYMax());
			e->fire(win);
			e->getBulletFactory()->advanceBullets(win.getYMax());
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> uid(0, 99999);
            if (uid(gen) % 10 == 0)
                e->spawnEnemy(win);
            Manager->EnemyKO();
            e->moveEnemy(win);
            if (Manager->PlayerKO())
                gameOver(win, Manager);
            Manager->EnemyKO();
			Fi->prinFigher(win);
			b->bulletPrinter(win);
            e->EnemyPrinter(win);
			e->getBulletFactory()->bulletPrinter(win);
            Manager->printInfo(win);

            createBoarder(win);
            wrefresh(win.getWin());
        }
    }
	delete b;
	delete Manager;
}
