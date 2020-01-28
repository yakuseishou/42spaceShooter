/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:13:55 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 19:15:47 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include "BaseUnit.hpp"
# include "window.hpp"

class Enemy : public BaseUnit {
    // int     _type; // store enemy type to identify their movemont paten
private:
	int	type;
	int	life;
	int	dir;
public:
    Enemy();
    Enemy(int y, int x);
    ~Enemy();
    Enemy(Enemy& other);
    Enemy& operator=(Enemy& other);

    int				advance(void);
	void			setType(int new_type);
	int				getType(void);
	void			setLife(int new_life);
	int				getLife(void);
	void			setDir(int new_dir);
	int				getDir(void);

	int				meteorMove(void);
	int				zigZagMove(void);
	void			shoot(void);
	void			print(Windo win);
	int				collides(int y, int x);
};

#endif
