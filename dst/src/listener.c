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

void			listener_keystroke(void)
{
	int			ret;
	char		buf[8];

	ft_bzero(buf, 8);
	while ((ret = read(0, buf, 8)))
	{
		buf[ret] = '\0';
		if (IS_ARROW(buf[0], buf[1]))
		{
			IS_KEY_UP(buf[2]) ? ft_putendl("key up") : 0;
			IS_KEY_RIGHT(buf[2]) ? ft_putendl("key right") : 0;
			IS_KEY_DOWN(buf[2]) ? ft_putendl("key down") : 0;
			IS_KEY_LEFT(buf[2]) ? ft_putendl("key left") : 0;
		}
		else if (IS_SPACE(buf[0]))
			ft_putendl("space");
	}
}
