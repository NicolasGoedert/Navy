/*
** my.h for my.h in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Jan 30 12:57:50 2017 DORIAN DEBOUT
** Last update Sat Feb 18 14:01:17 2017 DORIAN DEBOUT
*/

#ifndef MY_H
#define MY_H

#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[0m"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

void	my_putchar(char);
int	my_putstr(char *);
int	my_putnbr(int);
int	my_strlen(char *);
void	flag_h();
void	begin();
void	maps(char **, char **, char *);
char	**str_wordtab(char *);
void	printab(char **);
char	**complete_map1(char **, int);
char	**complete_map2(char **);
char	**vertical(char **, char **, int);
char	**horizontal(char **, char **, int);
char	**map2_print(char **);
char	**complete_enter(char **, char **, int);
char	**check_hit(char *, char **, int, int);
char	**check_hit2(char *, char **, int, int);
int	main3(int, char **);
int	main2(int, char **);
char	**complete_map3(char **, int);
char	**complete_map4(char **);
void	begin2();
int	check_pos(char **);
void	new_pos(int, char **);
int	check_pos3(char **);
char	**change_pos_send(char **, char *);
int	check_point(char **);
char	**map4_print(char **);
char	*convert(int);
int	int_len(int);
char	*cut(char *);
void	save_attack(char *);
char	**actu_map1(char **, char *, int, int);
int	my_getnbr(char *);
int	recup_epid();
int	recup_epid2();
int	verif_end(char *);
int	my_strcmp(char *, char *);
void	check_winner(int, int);
char	**ennemy(char **);
char	**waiting(char **);
void	waiting2();
int	check_argv(char **);
void	hand3(int, char *);
char	**ennemy2(char **);
void	reset_all();
int	check_same(char **);
char	**check_inverse(char **, char *);
int	check_position(char *, int);
int	check_superpos(char **, char *);
void	hit_miss1(char *, int);
void	argument(char **);
void	argument2(char **);
char	*check_order(char *);

#endif
