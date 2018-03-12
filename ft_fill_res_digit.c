/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_res_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:34:03 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:34:04 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	*ft_fill_res_digit(t_struc *struc, t_res *res)
{
	if (struc->flag[2] == ' ' && ft_is_needle("dDi", struc->type) == 1 &&
		struc->minus == 0)
	{
		res->arr = ft_join(res->arr, " ");
		res->count++;
	}
	if (struc->flag[2] == '+' && struc->minus == 0)
	{
		res->arr = ft_join(res->arr, "+");
		res->count++;
	}
	if (struc->minus == 1)
	{
		res->arr = ft_join(res->arr, "-");
		res->count++;
	}
	return (res);
}
