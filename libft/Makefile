NAME = libft.a

CC = cc

INC = -I.

FLAGS = -Wall -Wextra -Werror

SRCS =	\
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_atol.c \
		ft_atodouble.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_split_is_word.c \
		ft_split_count_word.c \
		ft_split_word_len.c \
		ft_split_dup_word.c \
		ft_free_s_matrix.c \
		ft_charset_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putchar_and_count_fd.c \
		ft_putstr_fd.c \
		ft_putstr_and_count_fd.c \
		ft_putendl_fd.c \
		ft_putendl_and_count_fd.c \
		ft_putnbr_fd.c \
		ft_putnbr_and_count_fd.c \
		\
		getnextline_srcs/get_next_line_bonus.c \
		getnextline_srcs/get_next_line_utils_bonus.c \
		\
		printf_srcs/srcs/direct_print_functions.c \
		printf_srcs/srcs/put_hexa_p.c \
		printf_srcs/srcs/ft_printf.c

BONUS =	\
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJS = ${SRCS:.c=.o}

BN_OBJS = ${BONUS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} -c ${FLAGS} ${INC} $< -o $@

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: ${OBJS} ${BN_OBJS}
	ar rcs ${NAME} ${OBJS} ${BN_OBJS}

clean:
	rm -f ${OBJS}
	rm -f ${OBJS} ${BN_OBJS}

fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re



