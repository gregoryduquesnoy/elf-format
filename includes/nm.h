/*
** nm.h for  in /home/duques_g/Programming/AUSP_nmobjdump
** 
** Made by duques_g
** Login   <duques_g@epitech.net>
** 
** Started on  Fri Apr 17 02:00:43 2015 duques_g
** Last update Sat Apr 18 20:00:26 2015 duques_g
*/

#ifndef NM_H_
# define NM_H_

# include <elf.h>

# define CNST_PTR const *const

# define B_TYPE (SHF_ALLOC | SHF_WRITE)
# define T_TYPE (SHF_ALLOC | SHF_WRITE)
# define R_TYPE (SHF_ALLOC | SHF_EXECINSTR)
# define D_TYPE (SHF_ALLOC)

# define UNUSED (__attribute__((unused)))
# define INLINE (inline __attribute__((always_inline)))

typedef struct		s_sym
{
  Elf64_Sym		*sym;
  Elf64_Sym		*end;
  char			*strtab;
}			t_sym;

typedef struct		s_stb
{
  char			sym;
  uint32_t		type;
}			t_stb;

typedef struct		s_type
{
  char			sym;
  uint32_t		type;
  uint64_t		flags;
}			t_type;

void	*get_data(char const *const filename);

void	print_symbols(t_sym *sym, Elf64_Shdr *shdr);

#endif /* !NM_H_ */
