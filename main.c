/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:47:58 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/01 02:07:00 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main(void)
{
	int i = 10;
	int *b = &i;

	ft_putnbr(ft_printf("This is a simple test.\nSecond sentence.\n")); 
	ft_putnbr(printf("This is a simple test.\nSecond sentence.\n")); 
	return (0);
}
