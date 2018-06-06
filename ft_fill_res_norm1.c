/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_res_norm1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:50:23 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/09 15:50:25 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	*ft_1_if_str_null(t_struc *struc, t_res *res)
{
	int		i;
	int		j;
	char	*str;
	char	*tmp;

	i = 0;
	j = 0;
	str = ft_strdup("(null)");
	while (i < (int)ft_strlen(struc->before_str) - struc->prec)
	{
		tmp = ft_strsub(struc->before_str, i, 1);
		res->arr = ft_join(res->arr, tmp);
		ft_strdel(&tmp);
		i++;
	}
	while (struc->width - i - j > 0)
	{
		tmp = ft_strsub(str, j, 1);
		res->arr = ft_join(res->arr, tmp);
		ft_strdel(&tmp);
		j++;
	}
	res->count = res->count + j + i;
	ft_strdel(&str);
	return (res);
}

t_res	*ft_2_if_str_null(t_struc *struc, t_res *res)
{
	int		i;
	int		j;
	char	*str;
	char	*tmp;

	i = 0;
	j = 0;
	str = ft_strdup("(null)");
	while (i < struc->prec)
	{
		tmp = ft_strsub(str, i, 1);
		res->arr = ft_join(res->arr, tmp);
		ft_strdel(&tmp);
		i++;
	}
	while (struc->width - i - j > 0)
	{
		tmp = ft_strsub(struc->after_str, i, 1);
		res->arr = ft_join(res->arr, tmp);
		ft_strdel(&tmp);
		j++;
	}
	res->count = res->count + j + i;
	ft_strdel(&str);
	return (res);
}

int		ft_if_str_null(t_struc *struc, t_res *res)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strdup("(null)");
	if (struc->before_str && struc->flag[1] == '0' &&
		struc->width >= struc->prec &&
		struc->width <= (int)ft_strlen(struc->before_str))
		res = ft_1_if_str_null(struc, res);
	else if (struc->after_str && struc->flag[1] == '-' &&
		struc->width < struc->prec &&
		struc->width < (int)ft_strlen(struc->after_str))
		res = ft_2_if_str_null(struc, res);
	else
	{
		res->arr = ft_join(res->arr, str);
		res->count += 6;
	}
	ft_strdel(&str);
	return (res->count);
}

t_res	*ft_hash_ox(t_struc *struc, t_res *res)
{
	if ((struc->type == 'o' || struc->type == 'O') && struc->flag[0] == '#'
		&& struc->str[0] != '0')
	{
		res->arr = ft_join(res->arr, "0");
		res->count++;
		struc->len++;
	}
	else if ((struc->type == 'x' || struc->type == 'X'))
	{
		if (struc->flag[0] == '#')
		{
			if (struc->str[0] != '\0' && struc->str[0] != '0')
			{
				res->arr = struc->type == 'x' ? ft_join(res->arr, "0x") :
				ft_join(res->arr, "0X");
				res->count += 2;
			}
		}
	}
	return (res);
}

t_res	*ft_prec_ws_wc(t_struc *struc, t_res *res)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = NULL;
	if (MB_CUR_MAX > 1)
	{
		count = ft_count_len_prec(struc);
		res->count += count;
		while (count > 0 && *struc->w_str)
		{
			tmp = ft_print_wchar(*struc->w_str, 0, 0);
			res->arr = ft_join(res->arr, tmp);
			count = count - ft_size_of_unicode(*struc->w_str);
			struc->w_str++;
		}
	}
	else
	{
		tmp = ft_strsub((char *)struc->w_str, 0, struc->prec);
		res->arr = ft_join(res->arr, tmp);
		res->count += struc->prec;
	}
	ft_strdel(&tmp);
	return (res);
}
