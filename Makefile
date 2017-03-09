# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 16:34:42 by ljoly             #+#    #+#              #
#    Updated: 2017/03/09 19:42:01 by ljoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ljoly.filler
SRCS = main.c filler.c tactics.c check_and_set.c graph.c
FLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/
HEADER = ./includes
OBJ = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
OBJ_PATH = ./obj/
SRCS_PATH = ./srcs/

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT) -lft -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
	@echo "$(GREEN)[✓]$(NC) Executable $(NAME) ready!"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(LIBFT) -o $@ -c $<
	@echo "$(GREEN)[✓]$(NC) Compiling" $<

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[-]$(NC) Objects cleaned..."

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@echo "$(RED)[-]$(NC) Executable $(NAME) cleaned..."

re: fclean all

.PHONY: $(NAME) all clean fclean re
