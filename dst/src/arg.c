/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:20:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/24 17:42:45 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			arg_init__(t_arg *this, char *name, int mode)
{
	this->name = ft_strdup(name);
	this->len = ft_strlen(name);
	this->mode = mode;
}

t_arg				*arg_new(char *name, int mode)
{
	t_arg			*arg;

	if (!(arg = (t_arg *)ft_memalloc(sizeof(t_arg))))
		return (NULL);
	arg_init__(arg, name, mode);
	return (arg);
}

void				arg_del(void *that)
{
	t_arg			*this;

	this = (t_arg *)that;
	free(this->name);
	free(this);
}

/*
** arg_print should be modified
*/
void				arg_print(void *that)
{
	t_arg		*this;

	this = (t_arg *)that;
	if (this->mode &= ARG_MODE_POINTED)
	{
		use_termcap("us");
		ft_putstr(this->name);
		use_termcap("ue");
	}
	else
		ft_putstr(this->name);
	ft_putstr("		");
}
