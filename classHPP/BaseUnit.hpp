/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseUnit.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:18:32 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 18:12:46 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEUNIT_HPP
# define BASEUNIT_HPP

# include <iostream>
# include <ctime>
# include <stdlib.h>

class BaseUnit {
protected:
    std::string   _s;
    int           _y;
    int           _x;
    // int     _heightF;
    // int     _widthF;
public:
    BaseUnit();
    BaseUnit(int y, int x);
    ~BaseUnit();
    BaseUnit(BaseUnit& other);
    BaseUnit& operator=(BaseUnit& other);

    std::string     getStr();
    int             getY();
    int             getX();
    // int     getHF();
    // int     getWF();
    void            setStr(std::string s);
    void            setY(int n);
    void            setX(int n);
	void			genPos(int max_y, int max_x);
};

#endif
