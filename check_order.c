/*
** check_order.c for check_order in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Sat Feb 18 13:45:36 2017 DORIAN DEBOUT
** Last update Sat Feb 18 13:56:11 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	*check_order(char *str)
{
  char	c;

  if (str[0] >= 'a' && str[0] <= 'z')
    str[0] = str[0] - 32;
  if (str[1] >= 'a' && str[1] <= 'z')
    str[1] = str[1] - 32;
  if (str[0] >= '0' && str[0] <= '9'
      || str[1] >= 'A' && str[1] <= 'Z')
    {
      c = str[0];
      str[0] = str[1];
      str[1] = c;
    }
  return (str);
}
