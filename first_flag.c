/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 20:09:10 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/30 19:43:42 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*first_flag(char *str, char *param, int *f, char c)
{
	if (ft_strchr("#0- +xs", param[f[5]]) == NULL)
		return (str = second_flag(str, param, f, c));
	else
	{
		if (param[f[5]] == '#' && f[0] == 0)
		{
			str = diese(str, c);
			f[0] = 1;
		}
		else if (param[f[5]] == '0' || param[f[5]] == '-' ||param[f[5]] == ' '
				|| param[f[5]] == '+')
			str = first_flag2(str, param, f, c);
		return (str);
	}
}

char	*first_flag2(char *str, char *param, int *f, char c)
{
	if (param[f[5]] == '0' && f[1] == 0)
	{
		f[1] = 1;
		return (zero(str, c));
	}
	else if (param[f[5]] == '-' && f[2] == 0)
	{
		f[2] = 1;
		return (moins(str, c));
	}
	else if (param[f[5]] == ' ' && f[3] == 0)
	{
		f[3] = 1;
		return (space(str, c));
	}
	else if (param[f[5]] == '+' && f[4] == 0)
	{
		f[4] = 1;
		return (plus(str, c));
	}
	else
		return (NULL);
}

char	*diese(char *str, char c)
{
	char	*new_str;
	int		i;

	if (ft_strchr("cCdDipsSuU", c) != NULL)
		return (str);
	else if (c == 'o' && str[0] != '0')
	{
		i = 0;
		new_str = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
		new_str[0] = '0';
		while (str[i])
		{
			new_str[i + 1] = str[i];
			i++;
		}
		new_str[i + 1] = '\0';
		free(str);
		return (new_str);
	}
	else if ((c == 'x' || c == 'X') && str[0] != '0')
		return (diese2(str, c));
}

char 	*diese2(char *str, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char*)malloc(sizeof(char) * ft_strlen(str) + 3);
	new_str[0] = '0';
	if (c == 'x')
		new_str[1] = 'x';
	else
		new_str[1] = 'X';
	while (str[i])
	{
		new_str[i + 2] = str[i];
		i++;
	}
	new_str[i + 2] = '\0';
	return (new_str);
}

char	*zero(char *str, char c)
{
	return (NULL);
}
