/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:34:26 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/01 21:54:35 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putwstr(wchar_t *s)
{
	int 	i;
	char	*str;

	i = 0;
	str = ft_strnew(0);
	while (s[i] != '\0')
	{
		str = ft_strjoin(str, ft_putwchar(s[i]));
		i++;
	}
	return (str);
}
