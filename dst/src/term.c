/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:20:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/24 17:42:45 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			term_init_data(void)
{
	char			*termtype;
	int				success;
	int				error;

	error = 0;
	if ((termtype = getenv("TERM")))
	{
		success = tgetent(NULL, (const char *)termtype);
		if (success > 0)
			return (1);
		if (success < 0)
			error_print(-1, NULL, "Terminfo database could not be found");
		else if (success == 0)
			error_print(-1, NULL, "No entry found");
	}
	else
		error_print(-1, NULL, "No terminal info passed in env.");
	return (-1);
}

int			term_init_config(struct termios *old_config)
{
	struct termios new;
	if (tcgetattr(0, old_config) == -1)
	{
		error_print(-1, NULL, "Struct termios can not be initialized.");
		return (-1);
	}
	new = *old_config;
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 1;
	tcsetattr(0, TCSANOW, &new);
	return (1);
}

int			term_out(int c)
{
	write(1, &c, 1);
	return (1);
}

void		term_restore(struct termios *termios)
{
	tcsetattr(0, TCSANOW, termios);
	cmd_put("ve");
	cmd_put("cl");
	exit(-1);
}
