/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:22:26 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 18:30:29 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <iostream>
# include <ncurses.h>
# include <random>
// # include "Fighter.hpp"

class Windo {
private:
    WINDOW*         _win;
    int             _y;
    int             _x;
    int             _yBeg;
    int             _xBeg;
    int             _yMax;
    int             _xMax;
    // char            _bt;
    // Fighter*        _Fi;
    int             _Bcount;
    // std::mt19937    _gen;

public:
    Windo(int y, int x, int yS, int xS);
    ~Windo();
    Windo(Windo& other);
    Windo& operator=(Windo& other);

    WINDOW* getWin();
    int     getY();    
    int     getX();
    int     getYBeg();
    int     getXBeg();
    int     getYMax();
    int     getXMax();
    // Fighter* getFighter();
    int     getBcount();
    std::mt19937    getGen();

    // void    setFighter(Fighter* Fi);
};

#endif
