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

static void			print_size(int i)
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	i = 0;
	use_termcap("cl");
	ft_putstr("col->");ft_putnbr(w.ws_col);
	ft_putendl("");
	ft_putstr("line->");ft_putnbr(w.ws_row);
	ft_putendl("");
}

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
	arglist_render(arglist);
	use_termcap("vs"); // show cursor
	while (read(0, NULL, 1))
	{
		signal(SIGWINCH, &print_size);
	}
	arglist_del(arglist);
	free(termios);
	return (0);
}
