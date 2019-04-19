NAME = libftprintf.a
SRC = ft_printf.c  other_function.c output.c flags_and_precision.c output_symbol.c output_digit.c specifiers_digit.c specifiers_symbol.c conversion.c
OBJ = ft_printf.o  other_function.o output.o flags_and_precision.o output_symbol.o output_digit.o specifiers_digit.o specifiers_symbol.o conversion.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
clean:
	@/bin/rm -f $(OBJ)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all clean
