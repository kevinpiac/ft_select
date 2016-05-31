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

static void			arg_init(char *name, t_arg *this)
{
	this->name = ft_strdup(name);
	this->len = ft_strlen(name);
	this->mode = 0;
}

t_arg				*arg_new(char *name)
{
	t_arg			*arg;

	if (!(arg = (t_arg *)ft_memalloc(sizeof(t_arg))))
		return (NULL);
	arg_init(name, arg);
	return (arg);
}

void				arg_del(t_arg *this)
{
	free(this->name);
	free(this);
}
