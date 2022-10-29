/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:27:33 by saeby             #+#    #+#             */
/*   Updated: 2022/10/29 14:00:38 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *input_str, ...)
{
	va_list params;
	va_start(params, input_str);
	size_t	w_chars;
	char	curr_char;
	char	next_char;

	w_chars = 0;
	while (*input_str != 0)
	{
		curr_char = *input_str;
		next_char = *(input_str + 1);
		//printf("%c", next_char);
		if (curr_char != '%')
			w_chars += ft_print_c(*input_str);
		else if (next_char == 'c')
		{
			w_chars +=ft_print_c((char) va_arg(params, int));
			input_str++;
		}
		else if (next_char == 's')
		{
			w_chars += ft_print_s((char*) va_arg(params, char*));
			input_str++;
		}
		else if (next_char == 'd')
		{
			w_chars += ft_print_d((int) va_arg(params, int));
			ft_putnbr((int) va_arg(params, int));
			input_str++;
		}
		input_str++;
	}
	va_end(params);
	return (w_chars);
}