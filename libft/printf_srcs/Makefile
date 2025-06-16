
NAME = printf_base.a

CC = cc
INC = -I.
FLAGS = -Wall -Wextra -Werror

LIBFT = ../libft_srcs/libft_base.a
#LIBFT_DIR = libft

SRCS = \
	srcs/put_hexa_p.c \
	srcs/direct_print_functions.c \
	srcs/ft_printf.c

OBJS = ${SRCS:.c=.o}

# Regola principale
all: ${NAME}

# Compila la libreria libft
#${LIBFT}:
#	@make bonus -C ${LIBFT_DIR}

# Crea la libreria del progetto unendo libft.a e i file oggetto del progetto
${NAME}: ${LIBFT} ${OBJS}
	@cp ${LIBFT} ${NAME}
	@ar -rcs ${NAME} ${OBJS}

# Regola per compilare i file .o
%.o: %.c
	${CC} ${FLAGS} ${INC} -c $< -o $@

# Pulisce i file oggetto del progetto e della libreria
clean:
#	@make clean -C ${LIBFT_DIR}
	rm -f ${OBJS}

# Pulisce tutto, inclusa la libreria finale
fclean: clean
#	@make fclean -C ${LIBFT_DIR}
	rm -f ${}${NAME}

# Ricompila tutto
re: fclean all

.PHONY: all clean fclean re


# NAME = libftprintf.a

# CC = cc

# INC = -I.

# FLAGS = -Wall -Wextra -Werror

# LIBFT = ./libft/libft.a

# SRCS = \
# 	srcs/put_hexa_p.c \
# 	srcs/direct_print_functions.c \
# 	srcs/ft_printf.c

# OBJS = ${SRCS:.c=.o}

# all: ${LIBFT} ${NAME}

# ${LIBFT}:
# 	@make bonus -C libft

# ${NAME}: ${OBJS}
# 	cp ${LIBFT} .
# 	ar -x libft.a
# 	ar -rcs ${NAME} ${OBJS} *.o
# 	rm -f *.o libft.a

# %.o: %.c
# 	${CC} ${FLAGS} ${INC} -c $< -o $@

# clean:
# 	@make clean -C libft
# 	rm -f ${OBJS}

# fclean: clean
# 	@make fclean -C libft
# 	rm -f ${NAME}

# re: fclean all

# .PHONY: all clean fclean re
