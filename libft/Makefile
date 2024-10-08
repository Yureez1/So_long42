NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
HEADER = libft.h
SOURCES = ft_bzero.c ft_calloc.c ft_memset.c ft_strchr.c \
		ft_strcmp.c ft_strcpy.c ft_strlen.c

OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
