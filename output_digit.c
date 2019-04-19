/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:46:16 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/18 17:46:23 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	sign_int_output(t_data data, long long int number)
{
	unsigned int	size;

	size = 0;
	if (data.widght == 0)
	{
		if (number < 0)
			size += f_putchar('-');
		else if (data.sign == '+' || data.sign == ' ')
			size += f_putchar(data.sign);
		size += putnbr(number, lenght_dec(ABS(number)), data.precision);
	}
	else
	{
		if (data.alignment == '-')
		{
			if (number < 0)
			{
				--data.widght;
				size += f_putchar('-');
			}
			else if (data.sign == '+' || data.sign == ' ')
			{
				--data.widght;
				size += f_putchar(data.sign);
			}
			size += putnbr(number, lenght_dec(ABS(number)), data.precision);
			if (data.precision != 0 || number != 0)
				data.widght -= (lenght_dec(ABS(number)) > data.precision ? lenght_dec(ABS(number)) : data.precision);
			if (data.widght > 0)
				while (data.widght-- > 0)
					size += f_putchar(' ');
		}
		else
		{
			if (number < 0)
			{
				--data.widght;
				if (data.alignment == '0')
					size += f_putchar('-');
			}
			else if (data.sign == '+' || data.sign == ' ')
			{
				--data.widght;
				if (data.alignment == '0')
					size += f_putchar(data.sign);
			}
			if (data.precision != 0 || number != 0)
				data.widght -= (lenght_dec(ABS(number)) >
					data.precision ?
					lenght_dec(ABS(number)) : data.precision);
			if (data.widght > 0)
				while (data.widght-- > 0)
					size += f_putchar(data.alignment);
			if (data.alignment != '0')
			{
				if (number < 0)
				{
					size += f_putchar('-');
				}
				else	if (data.sign == '+' || data.sign == ' ')
					size += f_putchar(data.sign);
			}
			size += putnbr(number,
			lenght_dec(ABS(number)), data.precision);
		}
	}
	return (size);
}

unsigned int	unsigned_int_output(t_data data, unsigned long long int number)
{
	unsigned int	size;

	size = 0;
	if (data.widght == 0)
		return (putnbr_uns(number, lenght_dec(number), data.precision));
	if (data.alignment == '-')
	{
		size += putnbr_uns(number, lenght_dec(number), data.precision);
		if (data.precision != 0 || number != 0)
			data.widght -= (lenght_dec(number) > data.precision ?
							lenght_dec(number) : data.precision);
		if (data.widght > 0)
			while (data.widght-- > 0)
				size += f_putchar(' ');
		return (size);
	}
	if (data.precision != 0 || number != 0)
		data.widght -= (lenght_dec(number) > data.precision ?
						lenght_dec(number) : data.precision);
	if (data.widght > 0)
		while (data.widght-- > 0)
			size += f_putchar(data.alignment);
	size += putnbr_uns(number, lenght_dec(number), data.precision);
	return (size);
}

unsigned int	unsigned_xint_output(t_data data, unsigned long long int number)
{
	unsigned int	size;

	size = 0;
	if (data.widght == 0)
	{
		if (data.sharp == '#')
			size += f_putstr(data.upp_registr == 'a' ? "0x" : "0X", 2);
		return (size + putnbr_hex(number, lenght_hex(number), data, data.upp_registr));
	}
	if (data.alignment == '-')
	{
		if (data.sharp == '#')
		{
			size += f_putstr(data.upp_registr == 'a' ? "0x" : "0X", 2);
			data.widght -= 2;
		}
		size += putnbr_hex(number,
		lenght_hex(number), data, data.upp_registr);
		if (data.precision != 0 || number != 0)
			data.widght -= (lenght_hex(number) > data.precision ?
			lenght_hex(number) : data.precision);
		if (data.widght > 0)
			while (data.widght-- > 0)
				size += f_putchar(' ');
		return (size);
	}
	if (data.sharp == '#')
	{
		if (data.alignment == '0')
			size += f_putstr(data.upp_registr == 'a' ? "0x" : "0X", 2);
		data.widght -= 2;
	}
	if (data.precision != 0 || number != 0)
		data.widght -= (lenght_hex(number) > data.precision ? lenght_hex(number) : data.precision);
	if (data.widght > 0)
		while (data.widght-- > 0)
			size += f_putchar(data.alignment);
	if (data.sharp == '#' && data.alignment != '0')
		size += f_putstr(data.upp_registr == 'a' ? "0x" : "0X", 2);
	size += putnbr_hex(number, lenght_hex(number), data, data.upp_registr);
	return (size);
}

unsigned int	unsigned_oint_output(t_data data, unsigned long long int number)
{
	unsigned int	size;

	size = 0;
	if (data.widght == 0)
	{
		if (data.sharp == '#')
		{
			--data.precision;
			size += f_putchar('0');
		}
		size += putnbr_octal(number, lenght_octal(number), data.precision);
	}
	else
	{
		if (data.alignment == '-')
		{
			if (data.sharp == '#')
			{
				size += f_putchar('0');
				--data.precision;
				--data.widght;
			}
			size += putnbr_octal(number, lenght_octal(number), data.precision);
			if (data.precision != 0 || number != 0)
				data.widght -= (lenght_octal(number) > data.precision ?
				lenght_octal(number) : data.precision);
			if (data.widght > 0)
				while (data.widght-- > 0)
					size += f_putchar(' ');
		}
		else
		{
			if (data.sharp == '#')
			{
				--data.precision;
				--data.widght;
			}
			if (data.precision != 0 || number != 0)
				data.widght -= (lenght_octal(number) > data.precision ?
				lenght_octal(number) : data.precision);
			if (data.widght > 0)
				while (data.widght-- > 0)
					size += f_putchar(data.alignment);
			if (data.sharp == '#')
				size += f_putchar('0');
			size += putnbr_octal(number, lenght_octal(number), data.precision);
		}
	}
	return (size);
}
