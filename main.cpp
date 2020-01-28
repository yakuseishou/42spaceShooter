/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:16:11 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/18 21:57:55 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include "prototype.hpp"
#include "classHPP/window.hpp"

int     exitGame() {
    endwin();
    exit(0);
}

int     main() {
    initscr(); // initialize
    cbreak();
    noecho();
    curs_set(0);
    refresh(); // refreshes the screen to match memory
    int x;
    int y;
    getyx(stdscr, y, x);
    Windo win(y, x, 0, 0); // WINDOW * win = newwin(60,100,0,0);
    refresh();

    gameStart(win);

    exitGame(); // deallocates
    return (0);
}
