/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:42:12 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/08 14:42:26 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define ABS(x) (x < 0 ? -1 * x : x)


typedef struct		s_data
{
	char			alignment;
	long int		widght;
	long int		precision;
	char			sharp;
	char			sign;
	char			upp_registr;
}					t_data;
//converion.c
unsigned long long int	conversion_unsigned_type(const char *format, unsigned long long int digit, char spec);
long long int			conversion_sign_type(const char *format, long long int digit, char spec);
char					search_type(const char *format, unsigned int *i);
//flags_and_precision.c
char					f_alignment(const char *format, char spec);
unsigned int			f_widght(const char *format, char spec);
char					f_sign(const char *format, char spec);
char					f_sharp(const char *format, char spec);
long int				f_precision(const char *format, char spec);
//ft_printf.c
int						ft_printf(const char *format, ...);
char					determinator_spec(const char *format, unsigned int *i);
unsigned int			specifier(const char *format, va_list argptr, char spec);
//other_function.c
int						conversion_digit(const char *format, unsigned int *i);
unsigned int			f_strlen(const char *s);
unsigned int			lenght_dec(unsigned long long int number);
//unsigned int			number_unsigned_lenght(unsigned long long int number);
unsigned int			lenght_hex(unsigned long long int number);
unsigned int			lenght_octal(unsigned long long int number);
//output_digit.c
unsigned int			sign_int_output(t_data data, long long int number);
unsigned int			unsigned_int_output(t_data data, unsigned long long int  number);
unsigned int			unsigned_xint_output(t_data data, unsigned long long int  number);
unsigned int			unsigned_oint_output(t_data data, unsigned long long int  number);
//output_symbol.c
unsigned int			line_output(t_data data, char *line);
unsigned int			symbol_output(t_data data, char symbol);
unsigned int			f_putstr(const char *s, unsigned int size);
unsigned int			f_putchar(char c);
//output.c
unsigned int			putnbr(long long int number, unsigned int number_lenght, long int precision);
unsigned int			putnbr_uns(unsigned long long int number, unsigned int number_lenght, long int precision);
unsigned int			putnbr_hex(unsigned long long int number, unsigned int number_lenght, t_data data, char spec);
unsigned int			putnbr_octal(unsigned long long int number, unsigned int number_lenght, long int precision);
//specifiers_digit.c
unsigned int			sign_dec_int(const char *format, va_list argptr, char spec);
unsigned int			unsigned_dec_int(const char *format, va_list argptr, char spec);
unsigned int			unsigned_hex_int(const char *format, va_list argptr, char spec);
unsigned int			unsigned_octal_int(const char *format, va_list argptr, char spec);
unsigned int			pointer(const char *format, va_list argptr, char spec);
//specisiers_symbol.c
unsigned int			symbol(const char *format, va_list argptr, char spec);
unsigned int			special_symbol(const char *format, char spec);
unsigned int			line(const char *format, va_list argptr, char spec);

#endif
