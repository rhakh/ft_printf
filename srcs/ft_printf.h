/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhakh <rhakh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:56:50 by rhakh             #+#    #+#             */
/*   Updated: 2017/02/28 15:15:10 by rhakh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <wctype.h>
# include <inttypes.h>

# define ABS(x) ((x)<0 ? -(x) : (x))
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\x1B[37m"
# define EOC		"\x1b[0m"

typedef enum		e_flags
{
	minus, plus, zero, hash, space
}					t_flags;

typedef enum		e_size_mod
{
	hh = 1, h, l, ll, j, z
}					t_size_mod;

typedef enum		e_conversion_letter
{
	s = 1, S, p, d, D, i, o, O, u, U, x, X, c, C, b, perc
}					t_conversion_letter;

typedef struct s_specifications	t_spec;

struct				s_specifications
{
	int				flags[space + 1];
	int				min_field_w;
	int				precision;
	int				size;
	int				conversion;
	char			alone_char;
	int				h_count;
	int				l_count;
	t_spec			*next;
};

typedef struct		s_strp
{
	char			*str;
	size_t			i;
	size_t			last_size;
}					t_strp;

int					ft_printf(const char *format, ...);
void				print_strp(t_strp *res);
t_spec				*new_spec(void);
void				erase_spec(t_spec *sp);
void				del_spec(t_spec *specs);
int					check_spec(t_spec *spec, char **str, va_list *cap);
int					check_conversion(t_spec *spec, char **str);
int					check_size(t_spec *sp, char **str);
int					check_precision(t_spec *spec, char **str, va_list *cap);
int					check_min_field(t_spec *spec, char **str, va_list *cap);
int					check_flags(t_spec *spec, char **str);
int					is_size(char *str);
int					is_flag(char *str);
t_strp				*get_result(char *format, t_spec *specs, va_list *ap,
					t_strp *res);
t_strp				*new_strp(size_t size);
void				del_strp(t_strp **t);
int					put_char_to_strp(t_strp *res, char c);
int					put_strp_to_strp(t_strp *res, t_strp *str);
int					put_str_to_strp(t_strp *res, char *str);
int					realloc_strp(t_strp *t);
t_strp				*get_spec(t_spec *sp, va_list *ap);
t_strp				*get_d_spec(t_spec *sp, va_list *ap);
void				d_flag_wout_min(t_spec *sp, t_strp *num, t_strp *f,
					long long v);
void				d_flag_with_min(t_spec *sp, t_strp *num, t_strp *f,
					long long v);
t_strp				*get_x_spec(t_spec *sp, va_list *ap);
void				x_flag_wout_min(t_spec *sp, t_strp *num, t_strp *f,
					unsigned long long v);
void				x_flag_with_min(t_spec *sp, t_strp *num, t_strp *f,
					unsigned long long v);
t_strp				*get_o_spec(t_spec *sp, va_list *ap);
void				o_flag_wout_min(t_spec *sp, t_strp *num, t_strp *f,
					unsigned long long v);
void				o_flag_with_min(t_spec *sp, t_strp *num, t_strp *f,
					unsigned long long v);
t_strp				*get_u_spec(t_spec *sp, va_list *ap);
void				u_flag_wout_min(t_spec *sp, t_strp *num, t_strp *field);
void				u_flag_with_min(t_spec *sp, t_strp *num, t_strp *field);
t_strp				*get_c_spec(t_spec *sp, va_list *ap);
void				c_flag_wout_min(t_spec *sp, char value, t_strp *field);
void				c_flag_with_min(t_spec *sp, char value, t_strp *field);
t_strp				*get_s_spec(t_spec *sp, va_list *ap);
void				s_flag_wout_min(t_spec *sp, char *value, t_strp *field);
void				s_flag_with_min(t_spec *sp, char *value, t_strp *field);
void				pre_processing(t_spec *sp);
t_strp				*get_prec_num(t_spec *sp, char *number);
unsigned long long	ucast_num(t_spec *sp, va_list *ap);
long long			cast_num(t_spec *sp, va_list *ap);
char				*ulltoa_base(unsigned long long num, int base);
void				ullpaste_in_str(unsigned long long num, int base,
					char *str, int *i);
char				*lltoa_base(long long num, int base);
void				llpaste_in_str(long long num, int base, char *str, int *i);
int					realloc_strp(t_strp *t);
void				str_capitalizer(char *str);
void				ft_putchar(char c);
void				ft_strdel(char **as);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
t_strp				*get_p_spec(t_spec *sp, va_list *ap);
void				p_flag_wout_min(t_spec *sp, t_strp *num, t_strp *f);
void				p_flag_with_min(t_spec *sp, t_strp *num, t_strp *f);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t len);
t_strp				*get_ls_spec(t_spec *sp, va_list *ap);
void				ls_flag_wout_min(t_spec *sp, wchar_t *value, t_strp *field);
void				ls_flag_with_min(t_spec *sp, wchar_t *value, t_strp *field);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					check_colour(t_strp *res, char **s);
t_strp				*alone_char(t_spec *spec, t_strp *tmp, t_strp *res);
t_strp				*get_b_spec(t_spec *sp, va_list *ap);
void				b_flag_wout_min(t_spec *sp, t_strp *num, t_strp *field,
					unsigned long long value);
void				b_flag_with_min(t_spec *sp, t_strp *num, t_strp *field,
					unsigned long long value);

#endif
