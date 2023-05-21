/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:45:32 by efirmino          #+#    #+#             */
/*   Updated: 2022/12/03 23:23:46 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_arg(uintptr_t nbr, int *count, char *base)
{
	if (nbr > 15)
	{
		ft_print_hex_arg(nbr / 16, count, base);
		ft_print_hex_arg(nbr % 16, count, base);
	}
	else
	{
		ft_print_char(base[nbr], count);
	}
}

void	ft_print_ex(unsigned int nbr, int *count, char *base)
{
	if (nbr > 15)
	{
		ft_print_ex(nbr / 16, count, base);
		ft_print_ex(nbr % 16, count, base);
	}
	else
	{
		ft_print_char(base[nbr], count);
	}
}
