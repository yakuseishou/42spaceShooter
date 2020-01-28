/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnEnBullet.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:43:59 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 03:43:59 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENBULLET_HPP
# define ENBULLET_HPP

# include <iostream>

class EnBullet {
private:
    std::string     _B;
    int             _yB;
    int             _xB;
public:
    EnBullet(int yF, int xF);
    ~EnBullet();
    EnBullet(EnBullet& other);
    EnBullet& operator=(EnBullet& other);

    std::string     getStrB() const;
    int             getYB();
    int             getXB();

    void            setYB(int n);
    void            setXB(int n);

	int				advance(void);
};

#endif