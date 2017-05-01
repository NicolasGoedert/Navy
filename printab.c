/*
** printab.c for printab in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy/reste
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Wed Feb  1 13:12:09 2017 DORIAN DEBOUT
** Last update Thu Feb  2 11:57:14 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

void	printab(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  my_putchar(tab[i][j]);
	  j = j + 1;
	}
      i = i + 1;
      my_putchar('\n');
    }
  my_putchar('\n');
}
