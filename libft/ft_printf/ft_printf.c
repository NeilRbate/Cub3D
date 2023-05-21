/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:59:58 by efirmino          #+#    #+#             */
/*   Updated: 2022/12/03 23:23:42 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count += 1;
		}
		else
		{
			i++;
			ft_print_finder(format[i], &args, &count);
		}
		i++;
	}
	va_end(args);
	return (count);
}

void	ft_print_finder(char c, va_list *arg_list, int *count)
{
	if (c == 'c')
		ft_print_char(va_arg(*arg_list, int), count);
	else if (c == 's')
		ft_print_str(va_arg(*arg_list, char *), count);
	else if (c == 'p')
		ft_print_arg(va_arg(*arg_list, void *), count);
	else if (c == 'd')
		ft_print_int(va_arg(*arg_list, int), count);
	else if (c == 'i')
		ft_print_int(va_arg(*arg_list, int), count);
	else if (c == 'u')
		ft_print_uint(va_arg(*arg_list, unsigned int), count);
	else if (c == 'x')
		ft_print_ex(va_arg(*arg_list, unsigned int), count, "0123456789abcdef");
	else if (c == 'X')
		ft_print_ex(va_arg(*arg_list, unsigned int), count, "0123456789ABCDEF");
	else if (c == '%')
		ft_print_char('%', count);
	else
		*count += 1;
	return ;
}
