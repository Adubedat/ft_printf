/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:23:10 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/30 21:13:40 by adubedat         ###   ########.fr       */
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
	int			digit;
	int			precision;
	int			modifier;
	char		conversion;
}				t_flags;

int				ft_printf(const char *str, ...);
int				check_conversion(char c);
char			*get_param(const char *str, int *i, char *c);
int				print_var(const char *str, int *i, va_list args);
int				distrib(const char *str, int i, va_list args);
int				print_string(char *param, va_list args, char c);
char			*first_flag(char *str, char *param, int *f, char c);
char			*first_flag2(char *str, char *param, int *f, char c);
char			*diese(char *str, char c);
char			*diese2(char *str, char c);
char			*zero(char *str, char c);
char			*moins(char *str, char c);
char			*space(char *str, char c);
char			*plus(char *str, char c);
char			*second_flag(char *str, char *param, int *f, char c);

#endif
