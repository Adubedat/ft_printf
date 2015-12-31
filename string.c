/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 19:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/31 22:49:40 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	sring_conv(va_list args, t_flags f)
{
	t_modifier	m;
	char		*str;
	int			len;

	if (f.modifier == 4 || f.conversion == 'S')
	{
		m.wstrt = va_arg(args, wchar_t*);
//		str = ???;
	}
	else
	{
		str = va_arg(args, char*);
		str = ft_strdup(str);
	}
//	str = apply_flags(str, f);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
