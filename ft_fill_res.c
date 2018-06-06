/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:36:54 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:36:55 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_compress(t_struc *struc, t_res *res)
{
	if (struc->flag[1] != '0' && struc->before_str != NULL)
	{
		res->arr = ft_join(res->arr, struc->before_str);
		res->count += ft_strlen(struc->before_str);
	}
	if (struc->str && ft_is_needle("dDi", struc->type) == 1)
		res = ft_fill_res_digit(struc, res);
	else if (struc->str && ft_is_needle("oOxX", struc->type) == 1)
		res = ft_hash_ox(struc, res);
	else if (struc->str && struc->type == 'p')
	{
		if (struc->prec == 0 && struc->dot == 1 && struc->str[0] == '0')
		{
			ft_strdel(&struc->str);
			struc->str = ft_strdup("\0");
		}
		res->arr = ft_join(res->arr, "0x");
		res->count += 2;
	}
	ft_prec_digit(struc, res);
	ft_prec_sc(struc, res);
}

int			ft_fill_res(t_struc *struc, t_res *res)
{
	if (!struc->str && !struc->w_str && ft_is_needle("sS", struc->type))
		return (ft_if_str_null(struc, res));
	else if (struc->str != NULL)
		struc->len = ft_strlen(struc->str);
	else
		struc->len = ft_count_bytes_of_unicode(struc->w_str);
	ft_compress(struc, res);
	if ((struc->type == 'c' && struc->str[0] == '\0') ||
		(struc->type == 'C' && struc->w_str[0] == '\0'))
		return (ft_wc_c_null(struc, res));
	if (struc->dot == 1 && struc->prec < struc->len &&
		ft_is_needle("SC", struc->type) == 1)
		res = ft_prec_ws_wc(struc, res);
	else
	{
		if (struc->w_str)
		{
			ft_wstr(struc, res);
			if (res->count == -1)
				return (res->count);
		}
	}
	ft_after_str(struc, res);
	return (res->count);
}
