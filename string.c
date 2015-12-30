/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 19:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/30 19:01:15 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_string(char *param, va_list args, char c)
{
	char *str;
	int	f[6];

	f[6] = {0};
	str = va_arg(args, char*);
	str = first_flag(str, param, f, c);
	ft_putstr(str);
}
