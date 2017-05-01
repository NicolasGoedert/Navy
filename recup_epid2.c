/*
** recup_epid2.c for recup pid j2 in /home/DoWdoX/test
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Feb  6 15:41:58 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:14:33 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	recup_epid2()
{
  int	epid;
  int	fd;
  char	*buff;

  fd = open("pid_j2", O_RDONLY);
  buff = malloc(sizeof(char) * 32000);
  read(fd, buff, 32000);
  epid = my_getnbr(buff);
  return (epid);
}
