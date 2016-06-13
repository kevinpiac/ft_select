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
	if (ARG_IS_POINTED(this->mode))
		cmd_put("us");
	if (ARG_IS_SELECTED(this->mode))
		cmd_put("mr");
	ft_putstr_fd(this->name, isatty(STDOUT_FILENO));
	cmd_put("me");
//	cmd_put("ue"); not needed if term supports mr...mb
}

void				arg_select(t_arglist *list)
{
	int			i;
	t_arg		*arg;

	cmd_put("cl");
	i = arglist_get_current_index(list);
	arg = list->args->items[i];
	arg->mode ^= ARG_MODE_SELECTED;
	move_right(list);
	arglist_render(list);
}
