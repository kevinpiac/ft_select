/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:13:16 by kevin             #+#    #+#             */
/*   Updated: 2016/03/04 14:18:06 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			listener_keystroke(t_arglist *list, struct termios *old_config)
{
	int			ret;
	char		buf[8];

	ft_bzero(buf, 8);
	while ((ret = read(0, buf, 8)))
	{
		buf[ret] = '\0';
		if (IS_ARROW(buf[0], buf[1]))
		{
			IS_KEY_UP(buf[2]) ? move_up(list) : 0;
			IS_KEY_RIGHT(buf[2]) ? move_right(list) : 0;
			IS_KEY_DOWN(buf[2]) ? move_down(list) : 0;
			IS_KEY_LEFT(buf[2]) ? move_left(list) : 0;
		}
		else if (IS_SPACE(buf[0]))
			arg_select(list);
		else if (IS_ENTER(buf[0]))
			term_restore(list, old_config, true);
		else if (IS_ESC(buf[0]))
			term_restore(list, old_config, false);
	}
}
