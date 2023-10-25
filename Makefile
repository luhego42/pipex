NAME		=		pipex

SRC			=		main.c \
					exec_cmd.c

OBJ			=		$(SRC:.c=.o)

CC			=		clang

CFLAGS		=		-g -Wall -Wextra -Werror

LIB.A		=		libft/libft.a

all			:		$(NAME)

$(NAME)		:		$(OBJ)
							make -sC libft
							clang $(CFLAGS) $(OBJ) $(LIB.A) -o $(NAME)

clean		:
							make clean -sC libft
							rm -f $(OBJ)

fclean		:		clean
							make fclean -sC libft
							rm -f $(NAME)

re			:		fclean all

.PHONY		:		all clean fclean re