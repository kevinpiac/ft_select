/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:20:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/24 17:42:45 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arglist		*g_arglist;
struct termios	*g_old_config;

int			main(int ac, char **av)
{
	t_arglist		*arglist;
	struct termios *old_config;
	if (ac < 2)			/* Should add an error handler here */
		return (1);
	if (term_init_data() == -1)
		return (1);
	if ((old_config = term_init_config()) == NULL)
		return (1);
	g_old_config = old_config;
	arglist = arglist_new(ac, av);
	g_arglist = arglist;
	arglist_render(arglist);
	signal_handler();
	listener_keystroke(arglist, old_config);
	return (0);
}
