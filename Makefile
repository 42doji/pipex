SRCS = file.c gnl_utils.c gnl.c \
pipex_utils.c pipex.c utils.c \
split1.c split2.c split3.c
OBJS = ${SRCS:.c=.o}
HEADER = pipex.h
NAME = pipex

BONUS_SRCS = file_bonus.c gnl_bonus.c gnl_utils_bonus.c \
here_doc_bonus.c pipex_bonus.c pipex_utils_bonus.c \
split1_bonus.c split2_bonus.c split3_bonus.c \
utils_bonus.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
BONUS_HEADER = pipex_bonus.h
BONUS_NAME = pipex_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_OBJS): %.o: %.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

