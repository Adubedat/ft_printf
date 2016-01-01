/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:47:58 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/01 22:31:24 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
#include <limits.h>

int	main(void)
{
	int i = 10;
	int *b = &i;
	char *str;

	ft_putnbr(ft_printf("{%10R}"));
	ft_putnbr(printf("{%10R}"));
	return (0);
}
