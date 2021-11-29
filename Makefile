SRCS		= ft_printf.c \
			  print_utils/ft_printchar.c \
			  print_utils/ft_printstr.c
OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
CC			= gcc -Wall -Wextra -Werror

%.o: %.c ft_printf.h
			${CC} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}

bonus:		${OBJS_BONUS} ft_printf.h
			ar rcs ${NAME} ${OBJS_BONUS}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
