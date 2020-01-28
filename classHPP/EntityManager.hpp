/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityManager.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:33:25 by alkozma           #+#    #+#             */
/*   Updated: 2020/01/19 03:26:07 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYMANAGER_HPP
# define ENTITYMANAGER_HPP

# include "BulletFactory.hpp"
# include "Enemy.hpp"
# include "Fighter.hpp"
# include "BaseUnit.hpp"
# include "EnemyController.hpp"
# include "window.hpp"

class	EntityManager {
	private:
		BulletFactory*		factory;	// contains array of bullets
		Fighter*			fighter;	// fighter
		EnemyController* 	econtrol;	// contains array of enemies
		// int					map_x;
		// int					map_y;
		int					tInit;
		int					tPlay;
	public:
		EntityManager();
		~EntityManager();
		EntityManager&	operator=(const EntityManager &x);
		EntityManager(const EntityManager &x);
		// void			tick();
		BulletFactory*		getBulletFactory();
		Fighter*			getFighter();
		EnemyController*	getEnemyController();
		// int					getMapX();
		// int					getMapY();
		void				setBulletFactory(BulletFactory *x);
		void				setFighter(Fighter *x);
		void				setEnemyController(EnemyController *x);
		// void				setMapX(int n);
		// void				setMapY(int n);
		// void				FighterKO();
		void				EnemyKO();
		bool				PlayerKO();
		void				printInfo(Windo	win);
		int					getTInit();
		void				setTInit(int n);
		int					getTPlay();
		void				setTPlay(int n);
};

#endif
