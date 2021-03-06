/*
** main.c for  in /home/duques_g/Programming/AUSP_nmobjdump/nm_src
**
** Made by duques_g
** Login   <duques_g@epitech.net>
**
** Started on  Fri Apr 17 01:51:05 2015 duques_g
** Last update Mon Apr 20 04:49:32 2015 duques_g
*/

#include <stdlib.h>
#include "nm.h"

static void	get_symbols_tab(t_sym *sym,
				void *data,
				Elf64_Shdr *shdr,
				int shnum)
{
  int		i;
  char		*str;

  i = -1;
  str = (char *)(data + shdr[((Elf64_Ehdr *)data)->e_shstrndx].sh_offset);

  while (++i != shnum)
    {
      printf("%s\n", &str[shdr[i].sh_name]);
      if (shdr[i].sh_type == SHT_SYMTAB)
	{
	  sym->sym = (Elf64_Sym *)(data + shdr[i].sh_offset);
	  sym->end = (Elf64_Sym *)((char *)sym->sym + shdr[i].sh_size);
	  sym->strtab = (char *)(data + shdr[shdr[i].sh_link].sh_offset);
	}
    }
}

void		get_elf(Elf64_Ehdr *ehdr)
{
  Elf64_Shdr	*shdr;
  t_sym		sym;

  shdr = (Elf64_Shdr *)((void *)ehdr + ehdr->e_shoff);
  get_symbols_tab(&sym, ehdr, shdr, ehdr->e_shnum);
  print_symbols(&sym, shdr);
}

int		main(int argc, char **argv)
{
  void		*data;

  if (argc != 2 || !(data = get_data(argv[1])))
    return (EXIT_FAILURE);
  get_elf(data);

  return (EXIT_SUCCESS);
}
