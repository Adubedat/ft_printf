/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:47:58 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/30 19:50:32 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main(void)
{
//	printf("je code %04o le %s", 42, "cul");
	ft_putnbr(ft_printf("je code %#x le %#s", "avec", "cul")); 
	return (0);
}
