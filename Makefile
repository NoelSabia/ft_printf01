NAME = libftprintf.a

SOURCES = ft_printf.c\
ft_words.c\
ft_numbers.c\

OBJ = ${SOURCES:.c=.o}

INCLUDES = ft_printf.h

CFLAGS = -Wall -Wextra -Werror -I ./

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all