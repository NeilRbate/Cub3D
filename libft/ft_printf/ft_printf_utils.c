/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:47:58 by efirmino          #+#    #+#             */
/*   Updated: 2022/12/03 23:23:50 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(int c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_print_str(char *str, int *count)
{
	int	i;

	if (!str)
	{
		ft_print_str("(null)", count);
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_print_char(str[i], count);
		i++;
	}
}

void	ft_print_arg(void *ptr, int *count)
{
	if ((uintptr_t)ptr == 0)
		ft_print_str("0x0", count);
	else
	{
		ft_print_str("0x", count);
		ft_print_hex_arg((uintptr_t)ptr, count, "0123456789abcdef");
	}
}

void	ft_print_int(int nbr, int *count)
{
	if (nbr == -2147483648)
	{
		ft_print_str("-2147483648", count);
	}
	else if (nbr < 0)
	{
		ft_print_char('-', count);
		ft_print_int(-nbr, count);
	}
	else if (nbr > 9)
	{
		ft_print_int(nbr / 10, count);
		ft_print_int(nbr % 10, count);
	}
	else
		ft_print_char('0' + nbr, count);
}

void	ft_print_uint(unsigned int nbr, int *count)
{
	if (nbr > 9)
	{
		ft_print_int(nbr / 10, count);
		ft_print_int(nbr % 10, count);
	}
	else
		ft_print_char('0' + nbr, count);
}
