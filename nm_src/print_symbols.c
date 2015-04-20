/*
** main.c for  in /home/duques_g/Programming/AUSP_nmobjdump/nm_src
**
** Made by duques_g
** Login   <duques_g@epitech.net>
**
** Started on  Fri Apr 17 01:51:05 2015 duques_g
** Last update Mon Apr 20 04:49:11 2015 duques_g
*/

#include <stdlib.h>
#include <stdio.h>
#include "nm.h"

static char		check_stb(Elf64_Sym CNST_PTR sym,
				  Elf64_Shdr CNST_PTR shdr __attribute__((unused)))
{
  char			c;
  register int		i;
  static t_stb const	stb[] = {{'u', STB_GNU_UNIQUE},
				 {'W', STB_WEAK},
				 {0, 0}};

  i = -1;
  c = -1;
  while (stb[++i].sym)
    if (ELF64_ST_BIND(sym->st_info) == stb[i].type)
      {
	c = stb[i].sym;
	if (c < 'a')
	  {
	    if (ELF64_ST_TYPE(sym->st_info) == STT_OBJECT)
	      c = 'W';
	    if (sym->st_shndx == SHN_UNDEF)
	      c += 32;
	  }
      }
  return (c);
}

static char		check_section(Elf64_Sym CNST_PTR sym,
				      Elf64_Shdr CNST_PTR shdr __attribute__((unused)))
{
  register int		i;
  static t_stb const	sctn[] = {{'U', SHN_UNDEF},
				  {'A', SHN_ABS},
				  {'C', SHN_COMMON},
				  {0, 0}};

  i = -1;
  while (sctn[++i].sym)
    if (sym->st_shndx == SHN_UNDEF)
      return (sctn[i].sym);
  return (-1);
}

static char		check_type(Elf64_Sym CNST_PTR sym, Elf64_Shdr CNST_PTR shdr)
{
  char			c;
  register int		i;
  static t_type const	type[] = {{'B', SHT_NOBITS, B_TYPE},
				  {'D', SHT_PROGBITS, D_TYPE},
				  {'T', SHT_PROGBITS, T_TYPE},
				  {'R', SHT_PROGBITS, R_TYPE},
				  {'D', SHT_DYNAMIC, 0},
				  {0, 0, 0}};

  c = -1;
  i = -1;
  while (type[++i].sym)
    {
      if (shdr[sym->st_shndx].sh_type == type[i].type
	  && shdr[sym->st_shndx].sh_flags == type[i].flags)
	{
	  c = type[i].sym;
	  return (c);
	}
    }
  return (c);
}

static char		get_type(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
  char			c;
  register int		i;
  static char		(*ptr[])(Elf64_Sym CNST_PTR,
				 Elf64_Shdr CNST_PTR) = {check_stb,
							 check_section,
							 check_type,
							 NULL};

  i = -1;
  c = -1;
  while (ptr[++i])
    {
      if ((c = ptr[i](sym, shdr)) != -1)
	break ;
    }
  if (c != -1 && ELF64_ST_BIND(sym->st_info) == STB_LOCAL)
    c += 32;
  return (c);
}

void		print_symbols(t_sym *sym, Elf64_Shdr *shdr)
{
  Elf64_Sym	*tmp;
  char		c;

  tmp = sym->sym;
  while (tmp != sym->end)
    {
      if (tmp->st_info == STT_SECTION || tmp->st_info == STT_FILE)
	{
	  ++tmp;
	  continue ;
	}
      c = get_type(tmp, shdr);
      if (tmp->st_value)
	printf("%016x %c %s\n", (unsigned int)tmp->st_value ,
	       c, &sym->strtab[tmp->st_name]);
      else
	printf("%18c %s\n", c, &sym->strtab[tmp->st_name]);
      ++tmp;
    }
}
