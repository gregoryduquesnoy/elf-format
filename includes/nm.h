/*
** nm.h for  in /home/duques_g/Programming/AUSP_nmobjdump
** 
** Made by duques_g
** Login   <duques_g@epitech.net>
** 
** Started on  Fri Apr 17 02:00:43 2015 duques_g
** Last update Fri Apr 17 02:21:58 2015 duques_g
*/

#ifndef NM_H_
# define NM_H_

#include <elf.h>

typedef struct		s_sym
{
  Elf64_Sym		*sym;
  Elf64_Sym		*end;
  char			*strtab;
}			t_sym;

void	*get_data(char const *const filename);

#endif /* !NM_H_ */
