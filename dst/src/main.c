/* ************************************************************************** */
/*                                        qqwq                                    */
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

int			main(int ac, char **av)
{
	struct termios	*termios;
	t_arglist		*arglist;

	if (ac < 2)
		return (1);
	if (term_init_data() == -1)
		return (1);
	termios = (struct termios *)ft_memalloc(sizeof(struct termios));
	if (term_init_config(termios) == -1)
		return (1);
	arglist = arglist_new(ac, av);
	cmd_put("cl"); /* clear terminal */
	cmd_put("vs"); /* show cursor */
	cmd_put("ks");/* allow keys */
	arglist_render(arglist);
	listener_keystroke();
//		signal(SIGWINCH, &print_size);
//		cmd_put("vi");
	arglist_del(arglist);
	free(termios);
	return (0);
}
