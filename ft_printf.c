/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:17:12 by kmieshko          #+#    #+#             */
/*   Updated: 2018/01/29 12:17:14 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_first_norm(int i, t_struc *struc, t_res *res)
{
	ft_read_struc(struc);
	if (ft_fill_res(struc, res) == -2)
	{
		res->ptr[res->k] = ft_strdup(ft_itoa_intmax(res->nb_null, 10, struc));
		res->k++;
	}
	i++;
	ft_del_struc(struc);
	return (i);
}

static int	ft_second_norm(const char *format, int i, t_res *res)
{
	char	*tmp;

	while (format[i] != '%' && format[i] && res->count != -1)
	{
		tmp = ft_strsub(format, i, 1);
		res->arr = ft_join(res->arr, tmp);
		ft_strdel(&tmp);
		res->count++;
		i++;
	}
	return (i);
}

static void	ft_while(const char *format, va_list arg_ptr, t_struc *struc,
	t_res *res)
{
	int		i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			struc = ft_fill_struc(arg_ptr, struc, format, i);
			i = struc->tmp + 1;
			ft_check_type(format[i], arg_ptr, struc);
			i = ft_first_norm(i, struc, res);
		}
		else
			i = ft_second_norm(format, i, res);
		if (res->count == -1)
			break ;
	}
	if (struc)
		free(struc);
}

int			ft_printf(const char *format, ...)
{
	int		ret;
	t_res	*res;
	t_struc	*struc;
	va_list	arg_ptr;

	va_start(arg_ptr, format);
	struc = NULL;
	res = ft_create_res(NULL);
	if (ft_strcmp(format, "%") == 0)
		return (0);
	ft_while(format, arg_ptr, struc, res);
	ret = ft_print_result(res, 0, 0, 0);
	ft_free_res(res);
	va_end(arg_ptr);
	return (ret);
}
