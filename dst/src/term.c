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

int			term_init_config(struct termios *termios)
{
	if (tcgetattr(0, termios) == -1)
	{
		error_print(-1, NULL, "Struct termios can not be initialized.");
		return (-1);
	}
	ft_bitprint(ICANON);
	ft_bitprint(ECHO);
	ft_bitprint(termios->c_lflag);
	termios->c_lflag &= ~(ICANON);
	//termios->c_lflag &= ~(ICANON | ECHO);
	termios->c_cc[VMIN] = 1;
	ft_bitprint(termios->c_lflag);

	tcsetattr(0, 0, termios);
	return (1);
}
