/*
** functions.c for functions in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Jan 30 12:55:09 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:11:16 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int	my_putnbr(int nb)
{
  long int	i;

  i = nb;
  if (i < 0)
    {
      my_putchar('-');
      i = i * -1;
    }
  if (i >= 10)
    my_putnbr(i / 10);
  i = i % 10 + '0';
  my_putchar(i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
