/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:15:01 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/01 22:26:16 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_flags(char *str, t_flags f)
{
	if (f.diese == 1 && str[0] != '0' && f.precision != 0)
	{
		if (f.conversion == 'o')
			str = ft_strjoin_free_s2("0", str);
		else if (f.conversion == 'x')
			str = ft_strjoin_free_s2("0x", str);
		else if (f.conversion == 'X')
			str = ft_strjoin_free_s2("0X", str);
	}
	if (f.space == 1 && str[0] != '-')
		str = ft_strjoin_free_s2(" ", str);
	if (f.plus == 1 && str[0] != '-')
		str = ft_strjoin_free_s2("+", str);
	return (apply_precision(str, f));
}

char	*apply_precision(char *str, t_flags f)
{
	if (f.precision != -1 && f.conversion == 's'
			&& ft_strlen(str) > (size_t)f.precision)
		str = ft_strsub_free(str, 0, f.precision);
	else if (f.precision != -1 && ft_strchr("dDioOuUxX", f.conversion) != NULL
			&& (size_t)f.precision > ft_strlen(str))
	{
		while ((size_t)f.precision > ft_strlen(str))
			str = ft_strjoin_free_s2("0", str);
	}
	return (apply_width(str, f));
}

char	*apply_width(char *str, t_flags f)
{
	while (ft_strlen(str) < (size_t)f.width)
	{
		if (f.zero == 0 && f.moins == 0)
			str = ft_strjoin_free_s2(" ", str);
		else if (f.zero == 1 && f.moins == 0)
			str = ft_strjoin_free_s2("0", str);
		else if (f.zero == 0 && f.moins == 1)
			str = ft_strjoin_free_s1(str, " ");
		else if (f.zero == 1 && f.moins == 1)
			str = ft_strjoin_free_s1(str, "0");
	}
	if (f.null == 0)
		ft_putstr(str);
	else
		ft_putstr_0(str);
	return (str);
}
