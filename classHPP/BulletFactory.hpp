/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletFactory.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:43:11 by alkozma           #+#    #+#             */
/*   Updated: 2020/01/19 18:44:40 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETFACTORY_HPP
# define BULLETFACTORY_HPP

# include <string>
# include "Bullet.hpp"
# include "window.hpp"

class	BulletFactory {
	private:
		Bullet*	bullets[256];
		int		amt;
		int		dir;
	public:
		BulletFactory();
		~BulletFactory();
		BulletFactory(const BulletFactory &x);
		BulletFactory&	operator=(BulletFactory &x);
		void		addBullet(int y, int x);
		void		advanceBullets(int max_y);
		void		bulletPrinter(Windo win);
		void		setAmt(int n);
		int			getAmt();
		void		setDir(int n);
		int			getDir();
		Bullet**	getBullets();
		void		deleteBullet(int i, int b);
};

#endif
