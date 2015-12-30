/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:41:34 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/29 20:41:04 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*get_param(const char *str, int *i, char *c)
{
	int 	j;
	int		k;
	char	*param;

	j = *i;
	k = 0;
	while (ft_strchr("sSpdDioOuUxXcC%", str[*i]) == NULL)
		*i = *i + 1;
	*c = str[*i];
	param = (char*)malloc(sizeof(char) * (*i - j) + 1);
	while (j <= *i)
	{
		param[k] = str[j];
		j++;
		k++;
	}
	param[k] = '\0';
	return (param);
}

void	print_var(const char *str, int *i, va_list args)
{
	char *param;
	char c;

	param = get_param(str, i, &c);
	if (c == 's')
		print_string(param, args);
}
