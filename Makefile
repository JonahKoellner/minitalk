CC = cc
CFLAGS = -Wall -Wextra -Werror
C_FILES = client.c
S_FILES = server.c
HEADER = minitalk.h
HELPER = helper.c
PRINTF = -Lprintf/ -lftprintf
LIBFT = -Lprintf/libft -lft
COBJS = ${C_FILES:.c=.o}
SOBJS = ${S_FILES:.c=.o}
RM	= rm -f

all:	client server

client: client.c
	@${CC} ${CFLAGS} ${PRINTF} ${LIBFT} ${HELPER} $< -o $@
	@printf "\e[3;33mCompiled Client !\e[0m\n"

server: server.c
	@${CC} ${CFLAGS} ${PRINTF} ${LIBFT} ${HELPER} $< -o $@
	@printf "\e[3;33mCompiled Server !\e[0m\n"

clean:
		@${RM} server && printf "\e[1;31m⚠️  Removed server ⚠️\e[0m\n"

		@${RM} client && printf "\e[1;31m⚠️  Removed client ⚠️\e[0m\n"

fclean:	clean

re:		fclean all

.PHONY:	all clean fclean re
