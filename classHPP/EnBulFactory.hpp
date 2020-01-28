/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnBulFactory.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:46:27 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 03:50:10 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENBULFACTORY_HPP
# define ENBULFACTORY_HPP

# include <string>
# include "EnBullet.hpp"
# include "window.hpp"

class	EnBulFactory {
	private:
		EnBullet*	bullets[256];
		int		amt;
	public:
		EnBulFactory();
		~EnBulFactory();
		EnBulFactory(const EnBulFactory &x);
		EnBulFactory&	operator=(EnBulFactory &x);
		void		addBullet(int y, int x);
		void		advanceBullets(void);
		void		bulletPrinter(Windo win);
		void		setAmt(int n);
		int			getAmt();
		EnBullet**	getBullets();
		// void		deleteBullet(int i, int b);
};

#endif