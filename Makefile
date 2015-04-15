##
## Makefile for  in /home/broggi_t/projet/Dining-Philosophers
## 
## Made by broggi_t
## Login   <broggi_t@epitech.eu>
## 
## Started on  Mon Feb 23 23:31:27 2015 broggi_t
## Last update Wed Feb 25 07:47:42 2015 duques_g
##

NAME_OBJDUMP	=	objdump
NAME_NM		=	nm

DIR_OBJDUMP	=	objdump_src
DIR_NM		=	nm_src

SRCS_OBJDUMP	+=	$(DIR_OBJDUMP)/main.c
SRCS_NM		+=	$(DIR_NM)/main.c

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-I includes

CC	=	gcc
RM	=	rm -f

OBJS_OBJDUMP	=	$(SRCS_OBJDUMP:.c=.o)
OBJS_NM		=	$(SRCS_NM:.c=.o)

%.o: %.c
			@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | sed 's/ /./2g'
			@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

all:			$(NAME_OBJDUMP) $(NAME_NM)

$(NAME_OBJDUMP):	$(OBJS_OBJDUMP)
			@$(CC) $(OBJS_OBJDUMP) -o $(NAME_OBJDUMP)
			@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME_OBJDUMP)  | sed 's/ /./2g'

$(NAME_NM):		$(OBJS_NM)
			@$(CC) $(OBJS_NM) -o $(NAME_NM)
			@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME_NM)  | sed 's/ /./2g'

clean:
			@$(RM) $(OBJS_OBJDUMP)
			@$(RM) $(OBJS_NM)
			@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS_OBJDUMP) | sed 's/ /./2g'
			@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS_OBJDUMP) | sed 's/ /./2g'

fclean:			clean
			@$(RM) $(NAME_OBJDUMP)
			@$(RM) $(NAME_NM)
			@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME_OBJDUMP) | sed 's/ /./2g'
			@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME_NM) | sed 's/ /./2g'

re:			fclean all

rebonus:		fclean bonus

.PHONY:			all bonus clean fclean re rebonus
