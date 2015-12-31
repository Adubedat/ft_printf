/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:24:57 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/31 22:46:37 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		char_conv(va_list args, t_flags f)
{
	t_modifier	m;
	int			len;
	char		*str;

	if (f.modifier == 4 || f.conversion == 'C')
	{
		m.wit = va_arg(args, wint_t);
//		str == ???
	}
	else if (f.conversion == '%')
		str = ft_strdup("%");
	else
	{
		m.i = va_arg(args, int);
		str = ft_strdup(&m.i);
	}
	if (f.conversion != '%')
//		str = apply_flags(str, f);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
