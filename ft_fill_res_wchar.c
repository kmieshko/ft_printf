/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_res_wchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:35:00 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:35:02 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	*ft_fill_res_wchar(t_struc *struc, t_res *res)
{
	char	*tmp;

	tmp = NULL;
	if (MB_CUR_MAX > 1)
	{
		tmp = ft_print_wchar(*struc->w_str, 0, 0);
		res->count += ft_size_of_unicode(struc->w_str[0]);
		res->arr = ft_join(res->arr, tmp);
		ft_strdel(&tmp);
	}
	else
	{
		if ((int)struc->w_str[0] >= 0 && (int)struc->w_str[0] <= 255)
		{
			res->count += 1;
			res->arr = ft_join(res->arr, (char *)struc->w_str);
		}
		else if ((int)struc->w_str[0] > 255)
		{
			res->count = -1;
			ft_strdel(&res->arr);
		}
	}
	return (res);
}
