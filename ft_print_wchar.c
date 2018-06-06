/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:27:28 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:27:29 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_byte(int print)
{
	int	byte;
	int	nb_bits;

	byte = 0;
	nb_bits = ft_nb_len(ft_convert_to_binary(print));
	if (nb_bits > 7 && nb_bits <= 11)
		byte = 1;
	else if (nb_bits > 11 && nb_bits <= 16)
		byte = 2;
	else
		byte = 3;
	return (byte);
}

char		*ft_print_wchar(wchar_t wchar, int i, int tmp)
{
	int		byte;
	int		mask;
	char	*arr;

	tmp = (int)wchar;
	arr = ft_strnew(6);
	byte = ft_count_byte(tmp);
	if (tmp < 127)
		arr[i] = tmp;
	else
	{
		mask = 256 - ft_recursive_power(2, (7 - byte));
		tmp = (tmp >> (byte * 6));
		tmp = tmp | mask;
		arr[i++] = tmp;
		while (byte > 0)
		{
			tmp = (int)wchar >> (6 * (byte - 1));
			tmp = tmp & 63;
			tmp = tmp | 128;
			arr[i++] = tmp;
			byte--;
		}
	}
	return (arr);
}
