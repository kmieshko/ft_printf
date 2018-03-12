/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_needle_flag_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:17:49 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:17:53 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_needle(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_flag(char *format, t_struc *struc, int i)
{
	int		j;
	char	*str;

	j = 0;
	struc->c_flag = 0;
	str = "#+- 0";
	if (ft_is_needle(str, format[i]) != 0)
	{
		if (format[i] == '#' && !struc->flag[0])
			struc->flag[0] = '#';
		else if (format[i] == '0' && struc->flag[1] != '-')
			struc->flag[1] = '0';
		else if (format[i] == '-')
			struc->flag[1] = '-';
		else if (format[i] == ' ' && !struc->flag[2])
			struc->flag[2] = ' ';
		else if (format[i] == '+')
			struc->flag[2] = '+';
		if (struc->flag[0] || struc->flag[1] || struc->flag[2])
		{
			struc->c_flag++;
			i = i + struc->c_flag;
		}
	}
	return (i);
}

int		ft_check_width(char *format, va_list arg_ptr, t_struc *struc, int i)
{
	char	*tmp;

	if (ft_is_needle("123456789*", format[i]) != 0)
	{
		if (format[i] > '0' && format[i] <= '9')
		{
			struc->width = ft_atoi(format + i);
			tmp = ft_itoa_intmax(struc->width, 10, struc);
			struc->c_width = ft_strlen(tmp);
			ft_strdel(&tmp);
		}
		else if (format[i] == '*')
		{
			struc->width = va_arg(arg_ptr, int);
			if (struc->width < 0)
			{
				struc->width = (-1) * struc->width;
				struc->flag[1] = '-';
			}
			arg_ptr = arg_ptr + 1;
			struc->c_width = 1;
		}
		i = i + struc->c_width;
	}
	return (i);
}
