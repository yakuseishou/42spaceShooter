/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:55:04 by kchen2            #+#    #+#             */
/*   Updated: 2020/01/19 02:40:36 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_HPP
# define PROTOTYPE_HPP

# include <iostream>
# include <ncurses.h>
# include <fstream>
# include "classHPP/window.hpp"
# include "classHPP/Fighter.hpp"
# include "classHPP/Bullet.hpp"
# include "classHPP/BaseUnit.hpp"
# include "classHPP/Enemy.hpp"
# include "classHPP/EnemyController.hpp"
# include "classHPP/EntityManager.hpp"

# define ESC_KEY 27
# define ENTER_KEY 10
/*main.cpp*/
int     exitGame();
/*gameStart.cpp*/
void    gameOver(Windo win, EntityManager* Manager);
void    gameStart(Windo win);
void    gameMenu(Windo win);
void    createBoarder(Windo win);
void    MenuKeyListen(Windo win);
void    startKeyListen(Windo win); 
/* GameMode.cpp*/
void    GameInit(Windo win);
void    prinFigher(Windo win, Fighter* Fi);

#endif
