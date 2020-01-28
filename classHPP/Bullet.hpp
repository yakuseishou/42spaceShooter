/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:08:21 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 17:19:38 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include <iostream>

class Bullet {
private:
    std::string     _B;
    int             _yB;
    int             _xB;
public:
    Bullet(int yF, int xF);
    ~Bullet();
    Bullet(Bullet& other);
    Bullet& operator=(Bullet& other);

    std::string     getStrB() const;
    int             getYB();
    int             getXB();

    void            setYB(int n);
    void            setXB(int n);

	int				advance(int dir);
};

#endif
