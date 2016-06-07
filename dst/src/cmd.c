/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:20:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/24 17:42:45 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			cmd_put(char *termcap)
{
	char			*res;

	if ((res = tgetstr(termcap, NULL)))
		tputs(res, 0, &term_out);
}


void	cmd_goto(int col, int line)
{
	char	*ptr;
	char	*ptr2;

	if ((ptr = tgetstr("cm", NULL)) != NULL)
		if ((ptr2 = tgoto(ptr, col, line)) != NULL)
			ft_putstr_fd(ptr2, isatty(STDOUT_FILENO));
}
