/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:21:54 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:21:55 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struc	*ft_fill_struc(va_list arg_ptr, t_struc *struc, const char *format,
	int i)
{
	int		j;
	char	*str;
	char	*arr;

	j = 0;
	str = "#+-0 .123456789hljz*";
	arr = ft_strchr(format + i, '%') + 1;
	struc = ft_create_struc(struc);
	while (arr[j] != '\0' && ft_is_needle(str, arr[j]))
	{
		j = ft_check_flag(arr, struc, j);
		j = ft_check_width(arr, arg_ptr, struc, j);
		j = ft_check_prec(arr, arg_ptr, struc, j);
		j = ft_check_size(arr, struc, j);
	}
	struc->tmp = i + j;
	return (struc);
}
