##
## Makefile for  in /home/duques_g/Programming/AUSP_nmobjdump
## 
## Made by duques_g
## Login   <duques_g@epitech.net>
## 
## Started on  Wed Apr 15 22:59:47 2015 duques_g
## Last update Sun Apr 19 23:04:35 2015 duques_g
##

NAME_NM		=	my_nm

DIR_NM		=	nm_src

SRCS_OBJDUMP	+=	$(DIR_OBJDUMP)/main.c

SRCS_NM		+=	$(DIR_NM)/main.c
SRCS_NM		+=	$(DIR_NM)/get_data.c
SRCS_NM		+=	$(DIR_NM)/print_symbols.c

CFLAGS		+=	-W -Wall -Wextra
CFLAGS		+=	-I includes
CFLAGS		+=	-g

CC		=	gcc
RM		=	rm -f

OBJS_NM		=	$(SRCS_NM:.c=.o)

%.o: %.c
			@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)
			@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | sed 's/ /./2g'

all:			nm objdump

objdump:		$(NAME_OBJDUMP)

$(NAME_NM):		$(OBJS_NM)
			@$(CC) $(OBJS_NM) -o $(NAME_NM)
			@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME_NM)  | sed 's/ /./5g'

nm:			$(NAME_NM)

clean:
			@$(RM) $(OBJS_OBJDUMP)
			@$(RM) $(OBJS_NM)
			@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS_NM) | sed 's/ /./3g'

fclean:			clean
			@$(RM) $(NAME_OBJDUMP)
			@$(RM) $(NAME_NM)
			@printf "[\033[0;35mdeleted\033[0m] % 30s\n" $(NAME_NM) | sed 's/ /./3g'

re:			fclean all

rebonus:		fclean bonus

.PHONY:			all bonus clean fclean re rebonus
