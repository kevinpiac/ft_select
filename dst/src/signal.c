/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:20:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/24 17:42:45 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_arglist		*g_arglist;
extern struct termios 	*g_old_config;

static void			term_tstp(struct termios *old_config)
{
	char	cp[3];

	cmd_put("cl");
	cmd_goto(0, 0);
	cmd_put("ve");
	cmd_put("te");
	tcsetattr(STDIN_FILENO, TCSANOW, old_config);
	signal(SIGTSTP, SIG_DFL);
	cp[0] = (old_config)->c_cc[VSUSP];
	cp[1] = '\n';
	cp[2] = '\0';
	ioctl(isatty(STDOUT_FILENO), TIOCSTI, &cp);
}

static void			signal_action(int sig)
{
	static int			nbr_col;
	int					new_nbr_col;

	new_nbr_col = size_calculate(g_arglist);
	nbr_col = nbr_col ? nbr_col : new_nbr_col;
	if (sig == SIGWINCH && new_nbr_col != nbr_col)
	{
		arglist_render(g_arglist);
		nbr_col = new_nbr_col;
	}
	else if (sig == SIGINT)
	{
		cmd_goto(0, 10);
		ft_putendl("Press escape to quit the program");
	}
	else if (sig == SIGTSTP)
	{
		term_tstp(g_old_config);
	}
	else if (sig == SIGCONT)
	{
		term_init_data();
		term_init_config();
		arglist_render(g_arglist);
	}
}

void			signal_handler(void)
{
	signal(SIGWINCH, &signal_action);
	signal(SIGINT, &signal_action);
	signal(SIGCONT, &signal_action);
	signal(SIGTSTP, &signal_action);
}
