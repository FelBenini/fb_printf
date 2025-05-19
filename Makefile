NAME = fb_printf.a

SRCS = ${wildcard srcs/*.c}

HDRS = includes/fb_printf.h

OBJS = ${SRCS:.c=.o}

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

srcs/%.o: srcs/%.c ${HDRS}
	${CC} ${CFLAGS} -I includes -c $< -o $@

$(NAME): $(OBJS)
	ar rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
