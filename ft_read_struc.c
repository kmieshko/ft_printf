/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_struc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:31:53 by kmieshko          #+#    #+#             */
/*   Updated: 2018/03/06 20:31:54 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_first_norm(t_struc *struc, int len)
{
	if (ft_is_needle("pdDiuUoOxX", struc->type) && struc->dot
		&& len < struc->prec)
		len = struc->prec;
	if (struc->flag[2] == ' ' && ft_is_needle("sc", struc->type) == 0)
		len++;
	if (ft_is_needle("dDi", struc->type) == 1)
		if (((struc->flag[2] == '+' && struc->minus == 0) || struc->minus))
			len++;
	if ((struc->flag[0] == '#') && (struc->type == 'o' || struc->type == 'O'))
		len++;
	if (struc->type == 'p' || (ft_is_needle("xX", struc->type) &&
		struc->flag[0] == '#' && struc->str[0] != '\0' && struc->str[0] != '0'))
		len = len + 2;
	return (len);
}

char		*ft_fill_space_from_width(t_struc *struc, int len)
{
	int		j;
	char	c;
	char	*arr;

	j = 0;
	c = struc->flag[1] == '0' ? '0' : ' ';
	len = ft_first_norm(struc, len);
	if (!(arr = ft_strnew(struc->width - len + 1)))
		return (NULL);
	while (struc->width - len - j > 0)
	{
		arr[j] = c;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

static void	ft_second_norm(t_struc *struc)
{
	if ((ft_is_needle("pdDiuUoOxX", struc->type) && struc->dot == 1)
		&& struc->flag[1] == '0')
		struc->flag[1] = '\0';
	if (struc->prec > 0 && ft_is_needle("sc", struc->type) == 1 &&
		struc->prec < struc->len)
		struc->len = struc->prec;
	if (struc->prec > 0 && ft_is_needle("SC", struc->type))
		struc->len = ft_count_len_prec(struc);
	if (!struc->prec && struc->dot && ft_is_needle("sScC", struc->type))
		struc->len = 0;
	if (struc->str && ((!struc->prec && struc->dot && struc->str[0] == '0') ||
		struc->str[0] == '\0') && ft_is_needle("pxXoOuU", struc->type))
		struc->len = 0;
	if ((struc->type == 'c' && struc->str[0] == 0) ||
		(struc->type == 'C' && struc->w_str[0] == 0))
		struc->len++;
}

void		ft_read_struc(t_struc *struc)
{
	if (!struc->str && !struc->w_str && !ft_is_needle("sS", struc->type))
		return ;
	else if (struc->str)
		struc->len = ft_strlen(struc->str);
	else if (struc->w_str)
	{
		if (struc->type == 'C')
			struc->len = ft_size_of_unicode(struc->w_str[0]);
		else
			struc->len = ft_count_bytes_of_unicode(struc->w_str);
	}
	ft_second_norm(struc);
	if (struc->len < struc->width)
		struc->before_str = ft_fill_space_from_width(struc, struc->len);
	if (struc->flag[1] == '-')
	{
		struc->after_str = struc->before_str;
		struc->before_str = NULL;
	}
}
