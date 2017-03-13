# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 16:13:48 by ljoly             #+#    #+#              #
#    Updated: 2017/03/10 12:02:18 by ljoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME) all clean fclean re

NAME = libft.a

SRC_IN = $(addprefix ./srcs/, $(SRC))
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_lstat.c ft_push_back.c ft_isspace.c ft_islower.c ft_isupper.c \
	ft_isxdigit.c ft_iscntrl.c ft_strlenchr.c ft_strdupchr.c \
	ft_strjoin_and_free.c get_next_line.c ft_chrpos.c ft_putnstr.c \
	ft_putnbr_sst.c ft_putnbr_st.c ft_power.c ft_print_hex.c ft_abs.c \
	ft_print_octal.c ft_putwchar.c ft_putwstr.c ft_wstrlen.c ft_wchar_size.c \
	ft_wstr_size.c ft_print_binary.c ft_count_w.c


OBJ = ${SRC:c=o}

HEADERS = ./includes

FLAGS = -Wall -Wextra -Werror

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC_IN) -I $(HEADERS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)[✓]$(NC) Library built..."

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[-]$(NC) Library cleaned..."

re: fclean all
