/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:37:42 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:37:45 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_result(t_res *res, int i, int sub, int ret)
{
	char	*arr;

	arr = res->arr;
	ret = res->count;
	while (res->count > 0)
	{
		sub = res->count;
		if (res->k > 0 && res->ptr[i] != '\0')
		{
			sub = i == 0 ? ft_atoi(res->ptr[i]) - 1 :
			ft_atoi(res->ptr[i]) - ft_atoi(res->ptr[i - 1]) - 1;
			write(1, arr, sub);
			write(1, "\0", 1);
			res->count = res->count - sub;
			arr = arr + sub;
			i++;
			res->k--;
		}
		else
		{
			write(1, arr, sub - i);
			res->count = 0;
		}
	}
	return (ret);
}
