/*
** reset_all.c for reset all in /home/DoWdoX/test
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Tue Feb  7 11:07:59 2017 DORIAN DEBOUT
** Last update Wed Feb  8 14:19:14 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

void	reset_maps1(char *buff, int i)
{
  int	fd;
  int	fd2;
  int	fd5;
  char	**tab;

  buff = malloc(sizeof(char) * 32000);
  fd = open("map_1", O_WRONLY);
  fd2 = open("map_2", O_WRONLY);
  fd5 = open("map_5", O_RDONLY);
  read(fd5, buff, 32000);
  tab = str_wordtab(buff);
  while (tab[i])
    {
      write(fd, tab[i], my_strlen(tab[i]));
      write(fd2, tab[i], my_strlen(tab[i]));
      if (i + 1 != 10)
	{
	  write(fd, "\n", 1);
	  write(fd2, "\n", 1);
	}
      i = i + 1;
    }
}

void	reset_maps2(char *buff, int i)
{
  int	fd;
  int	fd2;
  int	fd5;
  char	**tab;

  buff = malloc(sizeof(char) * 32000);
  fd = open("map_3", O_WRONLY);
  fd2 = open("map_4", O_WRONLY);
  fd5 = open("map_5", O_RDONLY);
  read(fd5, buff, 32000);
  tab =str_wordtab(buff);
  while (tab[i])
    {
      write(fd, tab[i], my_strlen(tab[i]));
      write(fd2, tab[i], my_strlen(tab[i]));
      if (i + 1 != 10)
	{
	  write(fd, "\n", 1);
	  write(fd2, "\n", 1);
	}
      i = i + 1;
    }
}

void	reset_all()
{
  char	*buff;

  reset_maps1(buff, 0);
  reset_maps2(buff, 0);
}
