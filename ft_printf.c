/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:21:37 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/29 20:08:55 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	distrib(const char *str, int i, va_list args)
{
	while (str[i] != '%' && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	if (str[i] == '%')
	{
		i++;
		print_var(str, &i, args);
		i++;
	}
	if (str[i])
		return (distrib(str, i, args));
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list		args;

	i = 0;
	va_start(args, str);
	distrib(str, i, args);
	va_end(args);
	return (0);
}
