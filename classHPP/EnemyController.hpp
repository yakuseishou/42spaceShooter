/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyController.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:50:17 by alkozma           #+#    #+#             */
/*   Updated: 2020/01/19 18:47:07 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYCONTROLLER_HPP
# define ENEMYCONTROLLER_HPP

# include <random>
# include "window.hpp"
# include "Enemy.hpp"
# include "BulletFactory.hpp"

class	EnemyController {
	private:
		//BulletFactory	*factory; (for when enemies shoot)
		Enemy*		enemies[256];
		int			amt;
		int			killscore;
		BulletFactory	*factory;
	public:
		EnemyController();
		~EnemyController();
		EnemyController(const EnemyController &x);
		EnemyController&	operator=(const EnemyController &x);

		void		spawnEnemy(Windo win);
		void		moveEnemy(Windo win); // change it to take in an integer to indentify movemont patten enemy->_type
		void		EnemyPrinter(Windo win);

		void		setAmt(int n);
		int			getAmt();
		Enemy**		getEnmy();
		BulletFactory	*getBulletFactory(void);
		void		setBulletFactory(BulletFactory *x);
		void		deleteEnemy(int a, int b);
		int			getKiScore();
		void		fire(Windo win);
};

#endif
