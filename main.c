/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:47:58 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/31 22:46:50 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main(void)
{
	long long int i;

	i = -2147483649;
	ft_printf("test %c %u\n", 850, i); 
//	ft_putchar('\n');
	printf("test %c %u", 850, i);
	return (0);
}
