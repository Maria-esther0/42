/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:49:00 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 22:29:04 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_int_len(int nbr);
static int	_prepend_char(t_flags *flags);

int	ft_print_d(int nbr, t_flags *flags)
{
	int	count;
	int	nbr_len;
	int	i;

	count = 0;
	i = 0;
	nbr_len = _int_len(nbr);
	if (flags->space || flags->plus)
		nbr_len++;

	if (flags->minus && flags->width > 0)
	{
		if (nbr >= 0 && (flags->space || flags->plus))
			count += _prepend_char(flags);
		count += ft_putnbr(nbr);
		while (i++ < flags->width - nbr_len)
			write(1, " ", 1);
	}
	else if (flags->minus == 0 && flags->width > 0)
	{
		while (i++ < flags->width - nbr_len)
			write(1, " ", 1);
		if (nbr >= 0 && (flags->space || flags->plus))
			count += _prepend_char(flags);
		count += ft_putnbr(nbr);
	}
	else 
	{
		count += _prepend_char(flags);
		count += ft_putnbr(nbr);
	}
	if (count < 0)
		return (-1);
	return (count);
}

static int	_prepend_char(t_flags *flags)
{
	int	count;

	count = 0;
	if ((flags->plus == 1) && (flags->space == 1))
		count += ft_putchar('+');
	else if ((flags->plus == 1) && (flags->space != 1))
		count += ft_putchar('+');
	else if ((flags->plus != 1) && (flags->space == 1))
		count += ft_putchar(' ');
	return (count);
}

static int	_int_len(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
