/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhakh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:56:40 by rhakh             #+#    #+#             */
/*   Updated: 2017/02/23 20:56:43 by rhakh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			realloc_strp(t_strp *t)
{
	char	*new_str;

	if ((new_str = ft_strnew(t->last_size * 2)) == NULL)
		return (0);
	ft_strncpy(new_str, t->str, t->last_size);
	free(t->str);
	t->str = new_str;
	t->last_size *= 2;
	return (1);
}

void		print_strp(t_strp *res)
{
	size_t		i;

	i = 0;
	while (i < res->i)
	{
		ft_putchar((res->str)[i]);
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_spec	*spec;
	int		res_len;
	t_strp	*res_str;
	va_list	ap;

	if ((spec = new_spec()) == NULL)
		return (-1);
	if ((res_str = new_strp(100)) == NULL)
		return (-1);
	va_start(ap, format);
	res_str = get_result((char *)format, spec, &ap, res_str);
	print_strp(res_str);
	res_len = (int)res_str->i;
	del_strp(&res_str);
	del_spec(spec);
	va_end(ap);
	return (res_len);
}
