/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ulli.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 20:53:09 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/31 23:36:16 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base_ulli(unsigned long long int value, int base,
		char c)
{
	char	*str;
	int		len;
	char	*b;

	if (c == 'x')
		b = ft_strdup("0123456789abcdef");
	else
		b = ft_strdup("0123456789ABCDEF");
	len = ft_ulli_len_base(value, base);
	str = (char*)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	if (value == 0)
	{
		str[0] = '0';
		return (str);
	}
	len--;
	while (value != 0)
	{
		str[len] = b[value % base];
		len--;
		value /= base;
	}
	return (str);
}
