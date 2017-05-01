##
## Makefile for Makefile in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
## 
## Made by DORIAN DEBOUT
## Login   <DoWdoX@epitech.net>
## 
## Started on  Mon Jan 30 10:45:35 2017 DORIAN DEBOUT
## Last update Sat Feb 18 14:01:38 2017 DORIAN DEBOUT
##

NAME	=	navy

SRCS	=	begin.c			\
		functions.c		\
		flag_h.c		\
		horiz_verti.c		\
		main2.c			\
		check_pos.c		\
		waiting.c		\
		check_position.c	\
		printab.c		\
		arg.c			\
		recup_epid2.c		\
		check_superpos.c	\
		check_hit.c		\
		check_argv.c		\
		actu_map1.c		\
		complete_map1.c		\
		verif_end.c		\
		check_order.c		\
		check_inverse.c		\
		check_winner.c		\
		reset_all.c		\
		complete_map2.c		\
		begin2.c		\
		main3.c			\
		check_hit2.c		\
		check_pos2.c		\
		complete_map3.c		\
		main.c			\
		complete_map4.c		\
		str_wordtab.c

OBJS	=	$(SRCS:.c=.o)

all: compile clean

compile:
	gcc $(SRCS) -o $(NAME) -L. -lgnl -g3

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: all fclean

.PHONY: all clean fclean re
