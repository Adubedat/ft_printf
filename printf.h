/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:23:10 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/31 14:56:58 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int			j;
	int 		diese;
	int			zero;
	int			moins;
	int			space;
	int			plus;
	int			width;
	int			precision;
	int			modifier;
	char		conversion;
	char		*param;
}				t_flags;

int				ft_printf(const char *str, ...);
char			*get_param(const char *str, int *i, char *c, char *param);
int				print_var(const char *str, int *i, va_list args);
int				distrib(const char *str, int i, va_list args);
int				print_string(va_list args, t_flags f);
t_flags			init_flags(t_flags f);
t_flags			check_first_flag(t_flags f);
t_flags			check_first_flag2(t_flags f);
t_flags			check_second_flag(t_flags f);
t_flags			check_third_flag(t_flags f);
t_flags			check_fourth_flag(t_flags f);

#endif
