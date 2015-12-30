/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:21:37 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/30 22:03:45 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*get_param(const char *str, int *i, char *c, char *param)
{
	int		j;
	int		k;

	j = *i;
	k = 0;
	while (ft_strchr("sSpdDioOuUxXcC%", str[*i]) == NULL)
		*i = *i + 1;
	*c = str[*i];
	fparam = (char*)malloc(sizeof(char) * (*i - j) + 1);
	while (j <= *i)
	{
		param[k] = str[j];
		j++;
		k++;
	}
	param[k] = '\0';
	return (param);
}

t_flags	init_flags(t_flags f)
{
	f.j = 0;
	f.diese = 0;
	f.zero = 0;
	f.moins = 0;
	f.space = 0;
	f.plus = 0;
	f.digit = 0;
	f.precision = 0;
	f.modifier = 0;
	return (f);
}

int		print_var(const char *str, int *i, va_list args)
{
	t_flags f;

	f.param = get_param(str, i, &f.conversion, f.param);
	f = init_flags(f);
	if (t.conversion == 's')
		return (print_string(f, args));
}

int	distrib(const char *str, int i, va_list args)
{
	static int	result = 0;

	while (str[i] != '%' && str[i])
	{
		write(1, &str[i], 1);
		i++;
		result++;
	}
	if (str[i] == '%')
	{
		i++;
		result += print_var(str, &i, args);
		i++;
	}
	if (str[i])
		return (distrib(str, i, args));
	return (result);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int result;
	va_list		args;

	i = 0;
	va_start(args, str);
	result = distrib(str, i, args);
	va_end(args);
	return (result);
}
