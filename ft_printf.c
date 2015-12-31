/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:21:37 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/31 15:13:48 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*get_param(const char *str, int *i, char *c, char *param)
{
	int		j;
	int		k;

	j = *i;
	k = 0;
	while (str[*i] && ft_strchr("sSpdDioOuUxXcC%", str[*i]) == NULL)
		*i = *i + 1;
	if (str[*i] == '\0')
		return (NULL);
	*c = str[*i];
	if (!(param = (char*)malloc(sizeof(char) * (*i - j) + 1)))
		return (NULL);
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
	f.width = 0;
	f.precision = -1;
	f.modifier = 0;
	return (f);
}

int		print_var(const char *str, int *i, va_list args)
{
	t_flags f;

	if (!(f.param = get_param(str, i, &f.conversion, f.param)))
		return (0);
	f = init_flags(f);
	if (f.conversion == 's')
		return (print_string(args, f));
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
		if (str[i])
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
