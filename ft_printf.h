/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:17:46 by kmieshko          #+#    #+#             */
/*   Updated: 2018/01/29 12:17:49 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <wchar.h>

# define FT_LIM 922337203685477580

typedef struct	s_struc
{
	char	flag[3];
	char	size[2];
	int		c_flag;
	int		width;
	int		c_width;
	int		dot;
	int		prec;
	int		c_prec;
	char	type;
	char	*str;
	wchar_t	*w_str;
	char	*before_str;
	char	*after_str;
	int		len;
	int		tmp;
	int		minus;
}				t_struc;

typedef struct	s_res
{
	char	*ptr[1024];
	char	*arr;
	int		count;
	int		nb_null;
	int		k;
}				t_res;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_recursive_power(int nb, int power);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
char			*ft_strnew(int size);
char			*ft_strdup(const char *str);
void			ft_strdel(char **as);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_convert_to_binary(int nb);
int				ft_nb_len(char *arr);
int				ft_size_of_unicode(wchar_t w_char);
int				ft_count_bytes_of_unicode(wchar_t *w_str);
int				ft_count_len_prec(t_struc *struc);
t_struc			*ft_create_struc(t_struc *struc);
t_res			*ft_create_res(t_res *res);
t_res			*ft_fill_res_wchar(t_struc *struc, t_res *res);
t_res			*ft_fill_res_digit(t_struc *struc, t_res *res);
t_res			*ft_fill_res_wstr(t_struc *struc, t_res *res);
t_res			*ft_1_if_str_null(t_struc *struc, t_res *res);
t_res			*ft_2_if_str_null(t_struc *struc, t_res *res);
int				ft_if_str_null(t_struc *struc, t_res *res);
t_res			*ft_hash_ox(t_struc *struc, t_res *res);
t_res			*ft_prec_ws_wc(t_struc *struc, t_res *res);
void			ft_prec_sc(t_struc *struc, t_res *res);
void			ft_prec_digit(t_struc *struc, t_res *res);
void			ft_after_str(t_struc *struc, t_res *res);
int				ft_wc_c_null(t_struc *struc, t_res *res);
void			ft_wstr(t_struc *struc, t_res *res);
int				ft_fill_res(t_struc *struc, t_res *res);
t_struc			*ft_fill_struc(va_list arg_ptr, t_struc *struc,
				const char *format, int i);
int				ft_count_nb(intmax_t nb, int base);
char			*ft_itoa_intmax(intmax_t nb, int base, t_struc *struc);
char			*ft_itoa_uintmax(uintmax_t nb, int base, char type);
char			*ft_join(char *s1, char *s2);
int				ft_is_needle(char *str, char c);
int				ft_check_flag(char *format, t_struc *struc, int i);
int				ft_check_width(char *format, va_list arg_ptr, t_struc *struc,
				int i);
int				ft_check_prec(char *format, va_list arg_ptr, t_struc *struc,
				int i);
int				ft_check_size(char *format, t_struc *struc, int j);
int				ft_print_result(t_res *res, int i, int sub, int ret);
char			*ft_print_wchar(wchar_t wchar, int i, int tmp);
void			ft_print_wstr(wchar_t *w_str);
int				ft_printf(const char *format, ...);
char			*ft_fill_space_from_width(t_struc *struc, int len);
void			ft_read_struc(t_struc *struc);
intmax_t		ft_check_spec(va_list arg_ptr, t_struc *struc);
uintmax_t		ft_check_unsigned_spec(va_list arg_ptr, t_struc *struc);
intmax_t		ft_check_big_d_spec(va_list arg_ptr, t_struc *struc);
uintmax_t		ft_check_big_ou_spec(va_list arg_ptr, t_struc *struc);
void			ft_digit_type(char type, va_list arg_ptr, t_struc *struc);
void			ft_charstring_type(char type, va_list arg_ptr, t_struc *struc);
void			ft_check_type(char type, va_list arg_ptr, t_struc *struc);
void			ft_del_struc(t_struc *struc);
void			ft_free_res(t_res *res);

#endif
