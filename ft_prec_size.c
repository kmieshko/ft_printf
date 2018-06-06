/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:18:31 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:18:32 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_neg_prec(t_struc *struc)
{
	struc->prec = 0;
	struc->dot = 0;
	struc->c_prec = 2;
}

int			ft_check_prec(char *format, va_list arg_ptr, t_struc *struc, int i)
{
	char	*tmp;

	if (format[i] == '.')
	{
		struc->dot = 1;
		if (format[i + 1] >= '0' && format[i + 1] <= '9')
		{
			struc->prec = ft_atoi(format + i + 1);
			tmp = ft_itoa_intmax(struc->prec, 10, struc);
			struc->c_prec = ft_strlen(tmp) + struc->dot;
			ft_strdel(&tmp);
		}
		else if (format[i + 1] == '*')
		{
			struc->prec = va_arg(arg_ptr, int);
			arg_ptr = arg_ptr + 1;
			struc->c_prec = 1 + struc->dot;
		}
		else
			struc->c_prec = struc->dot;
	}
	if (struc->prec < 0)
		ft_neg_prec(struc);
	i = i + struc->c_prec;
	return (i);
}

static void	ft_fill_size(t_struc *struc, char letter)
{
	if (struc->size[0] == letter)
		struc->size[1] = letter;
	else
		struc->size[0] = letter;
}

int			ft_check_size(char *format, t_struc *struc, int j)
{
	char	*str;

	str = "hljz";
	if (ft_is_needle(str, format[j]) != 0)
	{
		if (format[j] == 'l' && struc->size[0] != 'h' &&
			struc->size[0] != 'j' && struc->size[0] != 'z')
			ft_fill_size(struc, 'l');
		else if (format[j] == 'h' && struc->size[0] != 'l' &&
			struc->size[0] != 'j' && struc->size[0] != 'z')
			ft_fill_size(struc, 'h');
		else if (format[j] == 'j')
			struc->size[0] = 'j';
		else if (format[j] == 'z')
			struc->size[0] = 'z';
		if (struc->size[0] || struc->size[1])
			j++;
	}
	return (j);
}
