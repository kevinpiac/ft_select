/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:20:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/24 17:42:45 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			arglist_init__(t_arglist *this, int ac, char **av)
{
	int			i;

	i = 1;
	this->args = vector_new(ac);
	while (i < ac)
	{
		vector_add(this->args, arg_new(av[i]));
		i++;
	}
}

t_arglist			*arglist_new(int ac, char **av)
{
	t_arglist	*arglist;

	if (!(arglist = (t_arglist *)ft_memalloc(sizeof(t_arglist))))
		return (NULL);
	arglist_init__(arglist, ac, av);
	return (arglist);
}

void				arglist_del(t_arglist *this)
{
	if (this->args)
		vector_del(this->args, &arg_del);
	free(this);
}
