/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:13:16 by kevin             #+#    #+#             */
/*   Updated: 2016/03/04 14:18:06 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			move_right(t_arglist *list)
{
	int			i;
	int			total;
	t_arg		*arg;
	t_vector	*args;

	cmd_put("cl");
	args = list->args;
	total = args->total;
	i = arglist_get_current_index(list);
	arg = args->items[i];
	arg->mode &= ARG_MODE_SELECTED;
	arg = (i + 1 < total) ? args->items[i + 1] : args->items[0];
	arg->mode |= ARG_MODE_POINTED;
	arglist_render(list);
}

void			move_left(t_arglist *list)
{
	int			i;
	int			total;
	t_arg		*arg;
	t_vector	*args;

	cmd_put("cl");
	args = list->args;
	total = args->total;
	i = arglist_get_current_index(list);
	arg = args->items[i];
	arg->mode &= ARG_MODE_SELECTED;
	arg = (i - 1 >= 0) ? args->items[i - 1] : args->items[total - 1];
	arg->mode |= ARG_MODE_POINTED;
	arglist_render(list);
}

void			move_up(t_arglist *list)
{
	list = NULL;
	ft_putendl("move up");
}

void			move_down(t_arglist *list)
{
	list = NULL;
	ft_putendl("move down");
}
