/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:19:02 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:19:03 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_check_spec(va_list arg_ptr, t_struc *struc)
{
	intmax_t spec;

	if (struc->size[0] == 'z')
		spec = (size_t)va_arg(arg_ptr, void *);
	else if (struc->size[0] == 'j')
		spec = (intmax_t)va_arg(arg_ptr, void *);
	else if (struc->size[1] == 'l')
		spec = (long long int)va_arg(arg_ptr, void *);
	else if (struc->size[0] == 'l')
		spec = (long int)va_arg(arg_ptr, void *);
	else if (struc->size[1] == 'h')
		spec = (char)va_arg(arg_ptr, void *);
	else if (struc->size[0] == 'h')
		spec = (short)va_arg(arg_ptr, void *);
	else
		spec = (int)va_arg(arg_ptr, void *);
	return (spec);
}

uintmax_t	ft_check_unsigned_spec(va_list arg_ptr, t_struc *struc)
{
	uintmax_t unsigned_spec;

	if (struc->size[0] == 'z')
		unsigned_spec = (size_t)va_arg(arg_ptr, void *);
	else if (struc->size[0] == 'j')
		unsigned_spec = (uintmax_t)va_arg(arg_ptr, void *);
	else if (struc->size[1] == 'l')
		unsigned_spec = (unsigned long long int)va_arg(arg_ptr, void *);
	else if (struc->size[0] == 'l')
		unsigned_spec = (unsigned long int)va_arg(arg_ptr, void *);
	else if (struc->size[1] == 'h')
		unsigned_spec = (unsigned char)va_arg(arg_ptr, void *);
	else if (struc->size[0] == 'h')
		unsigned_spec = (unsigned short)va_arg(arg_ptr, void *);
	else
		unsigned_spec = (unsigned int)va_arg(arg_ptr, void *);
	return (unsigned_spec);
}

intmax_t	ft_check_big_d_spec(va_list arg_ptr, t_struc *struc)
{
	intmax_t spec;

	if (struc->size[0] == 'z')
		spec = (size_t)va_arg(arg_ptr, void *);
	else if (struc->size[0] == 'j')
		spec = (intmax_t)va_arg(arg_ptr, void *);
	else if (struc->size[1] == 'l')
		spec = (long long int)va_arg(arg_ptr, void *);
	else
		spec = (long int)va_arg(arg_ptr, void *);
	return (spec);
}

uintmax_t	ft_check_big_ou_spec(va_list arg_ptr, t_struc *struc)
{
	uintmax_t unsigned_spec;

	if (struc->size[0] == 'z')
		unsigned_spec = (size_t)va_arg(arg_ptr, void *);
	else if (struc->size[0] == 'j')
		unsigned_spec = (uintmax_t)va_arg(arg_ptr, void *);
	else if (struc->size[1] == 'l')
		unsigned_spec = (unsigned long long int)va_arg(arg_ptr, void *);
	else
		unsigned_spec = (unsigned long int)va_arg(arg_ptr, void *);
	return (unsigned_spec);
}
