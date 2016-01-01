/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 19:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/01 02:12:01 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	sring_conv(va_list args, t_flags f)
{
	t_modifier	m;
	char		*str;
	int			len;

	str = NULL;
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
	str = apply_flags(str, f);
	len = ft_strlen(str);
	free(str);
	return (len);
}
