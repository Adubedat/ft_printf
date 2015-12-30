/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:23:10 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/29 20:40:59 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		check_conversion(char c);
char	*get_param(const char *str, int *i, char *c);
void	print_var(const char *str, int *i, va_list args);
void	distrib(const char *str, int i, va_list args);
void	print_string(char *param, va_list args);

#endif
