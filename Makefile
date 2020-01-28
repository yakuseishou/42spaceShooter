# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/27 16:19:54 by kchen2            #+#    #+#              #
#    Updated: 2020/01/19 00:45:37 by kchen2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CC = clang++

FLAGS = -Wall -Werror -Wextra 

NCURSES = -lncurses

FILES = main \
		window \
		gameStart \
		GameMode \
		BaseUnit \
		Fighter	\
		Bullet	\
		BulletFactory \
		Enemy \
		EnemyController \
		EntityManager
	

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRCS) -IclassHPP 
	$(CC) $(NCURSES) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
