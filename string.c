/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 19:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/02 22:13:03 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*string_conv2(va_list args, t_flags f, t_modifier m, char *str)
{
	if (f.modifier == 4 || f.conversion == 'S')
	{
		m.wstrt = va_arg(args, wchar_t*);
		if (m.wstrt)
			str = ft_putwstr(m.wstrt, f.precision);
	}
	else if (str == NULL)
	{
		str = va_arg(args, char*);
		if (str)
			str = ft_strdup(str);
	}
	return (str);
}

int		string_conv(va_list args, t_flags f)
{
	t_modifier	m;
	char		*str;
	int			len;

	str = NULL;
	if (ft_strchr("sSpdDioOuUxXcC%", f.conversion) == NULL)
	{
		str = ft_strnew(1);
		str[0] = f.conversion;
	}
	str = string_conv2(args, f, m, str);
	if (str)
		str = apply_flags(str, f);
	else if (!(str) && check_s_flags(f.param) == 0)
		ft_putstr(str = ft_strdup("(null)"));
	else
	{
		free(str);
		str = ft_strdup("");
		str = apply_flags(str, f);
	}
	len = ft_strlen(str);
	free(str);
	free(f.param);
	return (len);
}

int		check_s_flags(char *param)
{
	int i;

	i = 0;
	while (param[i])
	{
		if (ft_strchr("0-.123456789", param[i]) != NULL)
			return (1);
		i++;
	}
	return (0);
}
