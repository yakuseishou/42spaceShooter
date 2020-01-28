/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fighter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:07:47 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/18 23:29:59 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGHTER_HPP
# define FIGHTER_HPP

# include <iostream>
# include "BaseUnit.hpp"
# include "window.hpp"
# include "BulletFactory.hpp"

class Fighter : public BaseUnit {
public:
    Fighter();
    Fighter(int yMax, int xMax);
    ~Fighter();
    Fighter(Fighter& other);
    Fighter& operator=(Fighter& other);

    void    movFiLeft();
    void    movFiRight(Windo win);
    void    movFiUp();
    void    movFiDown(Windo win);

    void    prinFigher(Windo win);
    void    shootBullet(BulletFactory *b);
};

#endif