/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:19:57 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:19:58 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_digit_type(char type, va_list arg_ptr, t_struc *struc)
{
	intmax_t	spec;
	uintmax_t	unsigned_spec;

	struc->type = type;
	if (ft_is_needle("dDi", type) == 1)
	{
		if (type == 'D')
			spec = ft_check_big_d_spec(arg_ptr, struc);
		else
			spec = ft_check_spec(arg_ptr, struc);
		struc->str = ft_itoa_intmax(spec, 10, struc);
	}
	else if (ft_is_needle("oOuUxX", type) == 1)
	{
		if (type == 'U' || type == 'O')
			unsigned_spec = ft_check_big_ou_spec(arg_ptr, struc);
		else
			unsigned_spec = ft_check_unsigned_spec(arg_ptr, struc);
		if (type == 'o' || type == 'O')
			struc->str = ft_itoa_uintmax(unsigned_spec, 8, type);
		else if (type == 'u' || type == 'U')
			struc->str = ft_itoa_uintmax(unsigned_spec, 10, type);
		else
			struc->str = ft_itoa_uintmax(unsigned_spec, 16, type);
	}
}

void	ft_charstring_type(char type, va_list arg_ptr, t_struc *struc)
{
	if (type == 'C' || (type == 'c' && struc->size[0] == 'l'))
	{
		struc->type = 'C';
		struc->w_str = (wchar_t *)ft_strnew(4);
		struc->w_str[0] = va_arg(arg_ptr, wchar_t);
	}
	else if (type == 'S' || (type == 's' && struc->size[0] == 'l'))
	{
		struc->w_str = va_arg(arg_ptr, wchar_t*);
		struc->type = 'S';
	}
	else if (type == 'c')
	{
		struc->type = 'c';
		struc->str = ft_strnew(1);
		struc->str[0] = va_arg(arg_ptr, int);
	}
	else if (type == 's')
	{
		struc->type = 's';
		struc->str = va_arg(arg_ptr, char *);
	}
}

void	ft_check_type(char type, va_list arg_ptr, t_struc *struc)
{
	if (ft_is_needle("dDioOuUxX", type) == 1)
	{
		ft_digit_type(type, arg_ptr, struc);
		if (struc->dot && struc->prec == 0 && ft_strcmp(struc->str, "0") == 0)
			struc->str[0] = '\0';
	}
	else if (type == 'p')
	{
		struc->flag[0] = '#';
		struc->size[0] = 'l';
		ft_digit_type('x', arg_ptr, struc);
		struc->type = 'p';
	}
	else if (ft_is_needle("cCsS", type) == 1)
		ft_charstring_type(type, arg_ptr, struc);
	else
	{
		struc->str = ft_strnew(1);
		struc->str[0] = type;
	}
}
