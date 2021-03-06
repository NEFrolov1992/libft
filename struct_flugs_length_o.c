/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_flugs_length_o.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:23:14 by gmentat           #+#    #+#             */
/*   Updated: 2020/01/03 22:15:03 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_f_l_h_o(t_f_arg *struct_flugs, t_arg *args, va_list ap)
{
	if (struct_flugs->fl != NULL || struct_flugs->z != NULL)
	{
		args->u.val_ul = va_arg(ap, unsigned long);
		args->str_result = ft_itoa_base(args->u.val_ul, 8);
	}
	else if (struct_flugs->t != NULL || struct_flugs->j != NULL)
	{
		args->u.val_ll = va_arg(ap, long long int);
		args->str_result = ft_itoa_base(args->u.val_ll, 8);
	}
	else if (struct_flugs->fll != NULL)
	{
		args->u.val_ull = va_arg(ap, unsigned long long);
		args->str_result = ft_itoa_base(args->u.val_ull, 8);
	}
	else
	{
		args->u.val_ui = va_arg(ap, unsigned int);
		if (struct_flugs->fh != NULL)
			args->str_result = ft_itoa_base(args->u.val_uh, 8);
		else if (struct_flugs->fhh != NULL)
			args->str_result = ft_itoa_base(args->u.val_uc, 8);
		else
			args->str_result = ft_itoa_base(args->u.val_ui, 8);
	}
}

char	*struct_flugs_length_o(t_f_arg *struct_flugs, t_arg *args, va_list ap)
{
	s_f_l_h_o(struct_flugs, args, ap);
	if (struct_flugs->point != NULL && struct_flugs->i_point == 0 &&
		(*(args->str_result) == '0' && args->u.val == 0))
	{
		ft_strdel(&args->str_result);
		args->str_result = ft_strnew(0);
	}
	return (args->str_result);
}
