NAME = push_swap

INC = inc/
LIBFT = ./libft_full.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -I


COMMAND_DIR = $(commands/ swap.c \
							rotate.c \
							rev_rotate.c \
							push.c\
							sort_three\
							sort_stacks.c\
							both_rotate.c\
							both_rev_rotate.c\	)

PUSH_SWAP_DIR = $(	push_swap.c\
				split.c\
				stack_init.c\
				stack_utils.c\
				info_nodes_a_to_b\
				info_nodes_b_to_b.c\
				handle_errors.c\	)

SRC = $(COMMAND_DIR) $(PUSH_SWAP_DIR)

OBJS :=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INC) $(LIBFT) $(OBJS) -o $(NAME)

%.o: %.c:
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re





