NAME = libftprintf.a

SRC = ft_printf.c ft_strlcpy.c ft_itoa.c\
ft_strdup.c ft_strlen.c ft_isdigit.c ft_lstnew.c\
ft_pitoa.c ft_put.c ft_uitoa.c ft_xitoa.c\
ft_lstfree.c
 
OBJ = ft_printf.o ft_strlcpy.o ft_itoa.o\
ft_strdup.o ft_strlen.o ft_isdigit.o ft_lstnew.o\
ft_pitoa.o ft_put.o ft_uitoa.o ft_xitoa.o\
ft_lstfree.o

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean:	clean
	/bin/rm -f $(NAME)
re:	fclean	all

.PHONY: all clean fclean re
