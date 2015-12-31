/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 19:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/31 15:23:02 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"

int	print_string(va_list args, t_flags f)
{
	char *str;

	str = va_arg(args, char*);
	str = ft_strdup(str);
	ft_putstr(str);
	f = check_first_flag(f);
	printf("\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%c\n%s\n", f.diese, f.zero, f.moins, f.space, f.plus, f.width, f.precision, f.modifier, f.conversion, f.param);
//	str = first_flag(str, f);
	return (ft_strlen(str));
}
