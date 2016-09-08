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

int					term_init_data(void)
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

struct termios		*term_init_config(void)
{
	struct termios new;
	struct termios *old_config;

	old_config = (struct termios *)ft_memalloc(sizeof(struct termios));
	if (tcgetattr(STDIN_FILENO, old_config) == -1)
	{
		error_print(-1, NULL, "Struct termios can not be initialized.");
		return (NULL);
	}
	new = *old_config;
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 1;
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
	cmd_put("ti");
	cmd_put("vi"); /* hide cursos */
	cmd_put("ks");/* allow keys */
	return (old_config);
}

int						term_out(int c)
{
	write(1, &c, 1);
	return (1);
}

void					term_restore(t_arglist *l, struct termios *t, t_bool p)
{
	tcsetattr(0, TCSANOW, t);
	cmd_put("ve");
	cmd_put("te");
	if (p == true)
		arglist_return(l);
	arglist_del(l);
	free(t);
	exit(-1);
}
