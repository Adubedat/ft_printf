/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:24:57 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/01 20:17:48 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*char_conv2(va_list args, t_flags f, char *str)
{
	t_modifier m;

	if (f.modifier == 4 || f.conversion == 'C')
	{
		m.wit = va_arg(args, wint_t);
//		str = wint_t_conv(m.wit, str);
	}
	else if (f.conversion == '%')
	{
		str = ft_strdup("%");
		str = apply_flags(str, f);
	}
	else
	{
		m.i = va_arg(args, int);
		if (m.i == 0)
			return (NULL);
		str = ft_strdup((const char*)&m.i);
	}
	return (str);
}

int		char_conv(va_list args, t_flags f)
{
	int			len;
	char		*str;

	len = 0;
	str = NULL;
	str = char_conv2(args, f, str);
	if (f.conversion != '%' && str)
	{
		str = apply_flags(str, f);
		len = ft_strlen(str);
		free(str);
	}
	else if (f.conversion == '%')
		len = ft_strlen(str);
	else if (str == NULL)
	{
		ft_putchar('\0');
		len = 1;
	}
	return (len);
}

/*char	*wint_t_conv(wint_t wit, char *str)
{

}*/
