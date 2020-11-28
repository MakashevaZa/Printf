NAME = ft_printf.a

SRC = ft_printf.c ft_strlcpy.c ft_itoa.c\
ft_strdup.c ft_strlen.c 
 
OBJ = ft_printf.o ft_strlcpy.o ft_itoa.o\
ft_strdup.o ft_strlen.o 

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

.PHONY: all bonus clean fclean re