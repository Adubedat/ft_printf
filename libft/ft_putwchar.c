/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 19:41:18 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/02 22:10:50 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*putwchar_print(char *str)
{
	int		i;
	char	*res;
	char	**split;

	i = 0;
	res = (char*)malloc(sizeof(char) * 5);
	split = ft_strsplit(str, ' ');
	while (split[i])
	{
		res[i] = ft_atoi_base(split[i], 2);
		i++;
	}
	free(split);
	return (res);
}

char	*putwchar_fill(char *mask, char *bin)
{
	int i;
	int j;

	j = ft_strlen(bin);
	i = ft_strlen(mask);
	i--;
	j--;
	while (i != -1 && j != -1)
	{
		if (mask[i] == 'x')
			mask[i] = bin[j--];
		i--;
	}
	if (i != -1)
		while (i != -1)
		{
			if (mask[i] == 'x')
				mask[i] = '0';
			i--;
		}
	return (mask);
}

char	*ft_putwchar(wint_t c)
{
	char	*bin;
	char	*mask;
	char	*str;
	int		len;

	bin = ft_itoa_base_ulli((unsigned long long int)c, 2, 'x');
	len = ft_strlen(bin);
	if (len <= 7)
		return (mask = ft_strdup((char*)&c));
	else
	{
		if (len <= 11)
			mask = ft_strdup("110xxxxx 10xxxxxx");
		else if (len <= 16)
			mask = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
		else
			mask = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
		mask = putwchar_fill(mask, bin);
		str = putwchar_print(mask);
		free(mask);
		free(bin);
		return (str);
	}
}
