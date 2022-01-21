# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 10:31:40 by mbehhar           #+#    #+#              #
#    Updated: 2022/01/20 18:56:55 by mbehhar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc

C_FLASGS	=	-Wall -Wextra -Werror

LIBFT		=	./libft/libft.a


OBJS		=	$(SRCS:%.c=%.o)

OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

SRCS		=	./src/print_stack.c \
				./src/ps_utils.c \
				./src/push.c \
				./src/rev_rot.c \
				./src/rotate.c \
				./src/swap.c \
				./src/check_errors.c \
				./src/free_data.c \
				./src/simple_sort.c \
				./src/find_median.c \
				./src/five_sort.c \
				./src/big_sort.c \

SRCS_BONUS	= 	./bonus/checker.c \
				./bonus/checker_utils.c \



%.o:%.c *.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m\e[1m%s\033[0m\n" "Compiling..."

all : $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(C_FLASGS) $(OBJS) ./src/main.c $(LIBFT) -o $(NAME)

bonus: $(OBJS_BONUS) $(OBJS)
	@make fclean -C libft
	@make -C libft
	@$(CC) $(C_FLASGS) $(OBJS) $(OBJS_BONUS) $(LIBFT) -o checker

clean:
	@make clean -C libft
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@rm -f checker

re: clean all