/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_res_norm2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:51:28 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/09 15:51:30 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_sc(t_struc *struc, t_res *res)
{
	char	*tmp;

	if (struc->dot == 1 && struc->prec < struc->len &&
		ft_is_needle("sc", struc->type) == 1)
	{
		tmp = ft_strsub(struc->str, 0, struc->prec);
		res->arr = ft_join(res->arr, tmp);
		ft_strdel(&tmp);
		res->count += struc->prec;
	}
	else
	{
		if (struc->str)
		{
			res->arr = ft_join(res->arr, struc->str);
			res->count += ft_strlen(struc->str);
		}
	}
}

void	ft_prec_digit(t_struc *struc, t_res *res)
{
	if (struc->flag[1] == '0' && struc->before_str != NULL)
	{
		res->arr = ft_join(res->arr, struc->before_str);
		res->count += ft_strlen(struc->before_str);
	}
	if (struc->len < struc->prec && ft_is_needle("dDioOuUxXp", struc->type))
	{
		while (struc->len < struc->prec)
		{
			res->arr = ft_join(res->arr, "0");
			res->count++;
			struc->len++;
		}
	}
}

void	ft_after_str(t_struc *struc, t_res *res)
{
	if (struc->after_str)
	{
		res->arr = ft_join(res->arr, struc->after_str);
		res->count += ft_strlen(struc->after_str);
	}
}

int		ft_wc_c_null(t_struc *struc, t_res *res)
{
	res->count++;
	res->nb_null = res->count;
	ft_after_str(struc, res);
	return (-2);
}

void	ft_wstr(t_struc *struc, t_res *res)
{
	if (struc->type == 'C' && struc->w_str[0])
		res = ft_fill_res_wchar(struc, res);
	else if (struc->type == 'S' && struc->w_str)
		res = ft_fill_res_wstr(struc, res);
	if (res->count == -1)
		ft_after_str(struc, res);
}
