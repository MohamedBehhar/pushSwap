NAME		=	push_swap

CC			=	gcc

C_FLASGS	=	-Wall -Wextra -Werror
# C_FLASGS	=	-g -Og -std=gnu99

LIBFT		=	./libft/libft.a


SRCS		=	./src/print_stack.c \
				./src/ps_utils.c \
				./src/push.c \
				./src/rev_rot.c \
				./src/rotate.c \
				./src/swap.c \
				./src/check_errors.c \
				./src/free_data.c \
				./src/sortingTest.c \
				./src/test.c 

OBJS		=	$(SRCS:%.c=%.o)

%.o:%.c *.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m\e[1m%s\n" "Compiling..."

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@$(CC) $(C_FLASGS) $(OBJS) $(LIBFT) -o $(NAME)

clean :
	@make clean -C libft
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME) 

re : clean all