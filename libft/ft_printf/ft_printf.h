/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:12:46 by efirmino          #+#    #+#             */
/*   Updated: 2022/12/03 23:24:54 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_print_finder(char c, va_list *arg_list, int *count);

/* SINGLE FUNCTIONS - SINGLE FUNCTION - SINGLE FUNCTION - SINGLE FUNCTION */
void	ft_print_char(int c, int *count);
void	ft_print_str(char *str, int *count);
void	ft_print_arg(void *ptr, int *count);
void	ft_print_int(int nbr, int *count);
void	ft_print_uint(unsigned int nbr, int *count);
void	ft_print_hex_arg(uintptr_t nbr, int *count, char *base);
void	ft_print_ex(unsigned int nbr, int *count, char *base);
/* SINGLE FUNCTIONS - SINGLE FUNCTION - SINGLE FUNCTION - SINGLE FUNCTION */

#endif