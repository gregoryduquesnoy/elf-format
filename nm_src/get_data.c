/*
** get_data.c for  in /home/duques_g/Programming/AUSP_nmobjdump/nm_src
** 
** Made by duques_g
** Login   <duques_g@epitech.net>
** 
** Started on  Fri Apr 17 01:54:39 2015 duques_g
** Last update Fri Apr 17 02:02:48 2015 duques_g
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stddef.h>
#include <stdio.h>
#include "nm.h"

void		*get_data(char const *const filename)
{
  void		*data;
  int		fd;
  int		end;

  if ((fd = open(filename, O_RDONLY)) == -1)
    {
      perror("open");
      return (NULL);
    }
  if ((end = lseek(fd, 0, SEEK_END)) == (off_t)-1)
    {
      perror("lseek");
      return (NULL);
    }
  if (!(data = mmap(NULL, end, PROT_READ, MAP_SHARED, fd, 0)))
    {
      perror("mmap");
      return (NULL);
    }
  return (data);
}
