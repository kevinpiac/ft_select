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

int			main(void)
{
	struct termios	*termios;

	if (term_init_data() == -1)
		return (1);
	termios = (struct termios *)ft_memalloc(sizeof(struct termios));
	if (term_init_config(termios) == -1)
		return (1);
	ft_putstr("Ready");
	return (0);
}
