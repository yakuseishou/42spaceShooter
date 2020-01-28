/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameStart.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:52:44 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/20 17:14:41 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <ncurses.h>
#include "prototype.hpp"

void    createBoarder(Windo win) {
    char bt;

    bt = '*';

    wborder(win.getWin(), (int)bt, (int)bt, (int)bt, (int)bt, (int)bt, 
        (int)bt, (int)bt, (int)bt);
}

void    gameOver(Windo win, EntityManager* Manager) {

    // std::ifstream in("ascii_arts/gameOver.txt");
    // std::string cont((std::istreambuf_iterator<char>(in)), 
    // std::istreambuf_iterator<char>());
    // mvwprintw(win.getWin(), 10, 0, cont.c_str());

	std::string contents = "   GAME OVER!\n   Final Score: ";
    if (!Manager)
	{

	}
    contents += std::to_string(Manager->getEnemyController()->getKiScore());
    contents += "\n   Press Enter to continue!\n";

    wclear(win.getWin());
    mvwprintw(win.getWin(), win.getYMax()/2 - 2, 2, contents.c_str());

    createBoarder(win);
    
    wrefresh(win.getWin());
    while (1) {
        char c = getch();
		if (c == '\033') {
            c = getch();
            if (c == ESC_KEY)
			{
                exitGame();
				break ;
			}
        }
        else if (c == ENTER_KEY)
		{
            gameMenu(win);
			break ;
		}
    }
}

void    MenuKeyListen(Windo win) {
    switch (getch()) {
        case 'c':
            GameInit(win);
            break;
        case 'q':
            exitGame();
            break;
        default:
            MenuKeyListen(win);
            break;
    }
}

void    gameMenu(Windo win) {
    
    std::ifstream cho("ascii_arts/choice.txt");
    std::string chos((std::istreambuf_iterator<char>(cho)), 
    std::istreambuf_iterator<char>());
	// std::string chos = "    Make your choice!";

    std::ifstream gs("ascii_arts/gameStart.txt");
    std::string gss((std::istreambuf_iterator<char>(gs)), 
    std::istreambuf_iterator<char>());
	// std::string gss = "    Game Start (c)";

    std::ifstream ex("ascii_arts/exit.txt");
    std::string exs((std::istreambuf_iterator<char>(ex)), 
    std::istreambuf_iterator<char>());
	// std::string exs = "    Exit (q)";

    wclear(win.getWin());
    mvwprintw(win.getWin(), 5, 0, chos.c_str());
    mvwprintw(win.getWin(), (win.getYMax()/2 - 10), 0, gss.c_str());
    mvwprintw(win.getWin(), (win.getYMax()/2 - 5), 0, exs.c_str());


    createBoarder(win);
    wrefresh(win.getWin());
    MenuKeyListen(win);
}

void    startKeyListen(Windo win) {
    switch (getch()) {
        case ENTER_KEY:
            gameMenu(win);
            break;
        case 'q':
            exitGame();
            break;
        default:
            startKeyListen(win);
            break;
    }
}

void    gameStart(Windo win) {
	// std::string contents = "     FT_RETO\n     (Press Enter!)";
    std::ifstream in("ascii_arts/ft_retro.txt");
    std::string contents((std::istreambuf_iterator<char>(in)), 
    std::istreambuf_iterator<char>());
    wclear(win.getWin());
        mvwprintw(win.getWin(), (win.getYMax()/2 - 15), 0, contents.c_str());

    createBoarder(win);
    wrefresh(win.getWin());
    startKeyListen(win);
}
