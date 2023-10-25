# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luhego <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:45:23 by luhego            #+#    #+#              #
#    Updated: 2023/07/28 15:41:30 by luhego           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	cc

SRC			=	ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
		 		ft_isdigit.c \
				ft_isprint.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strlen.c \
				ft_memcpy.c \
				ft_memcmp.c \
				ft_strncmp.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_memchr.c \
				ft_strdup.c \
				ft_memmove.c \
				ft_strrchr.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_atoi.c \
				ft_strnstr.c \
				ft_calloc.c \
				ft_substr.c \
				ft_striteri.c \
				ft_strmapi.c \
				ft_itoa.c \
				ft_strtrim.c \
				ft_strjoin.c \
				ft_split.c \
				get_next_line.c \
				ft_putstr_count.c \
				ft_putchar_count.c \
				ft_putnbr_base.c \
				ft_unsigned_putnbr.c \
				ft_printf.c \
				ft_free_double_tab.c

SRC_BONUS	= 	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c
				
OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror

MAKEFLAGS	=	--no-print-directory

ifdef			bonus
				SRC += $(SRC_BONUS)
endif

$(NAME)		:	$(OBJ)
					ar rc $(NAME) $(OBJ)

all			:	$(NAME)

bonus		:	$(OBJ) $(OBJ_BONUS)
					@make bonus=1

clean		:
					rm -rf $(OBJ) $(OBJ_BONUS)
					@echo ".o files have been removed"

fclean		:	clean
					rm -rf $(NAME)
					@echo ".o and .a files have been removed"

re			:	fclean all

.PHONY		:	all bonus clean fclean re
