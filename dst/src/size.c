/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:20:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/24 17:42:45 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				size_put(struct winsize w)
{
	ft_putstr("col->");ft_putnbr(w.ws_col);
	ft_putendl("");
	ft_putstr("line->");ft_putnbr(w.ws_row);
	ft_putendl("");
}

struct winsize		size_get(void)
{
	struct winsize		w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w);
}

int					size_get_row(void)
{
	struct winsize		w;

	w = size_get();
	return (w.ws_row);
}

int					size_get_col(void)
{
	struct winsize		w;

	w = size_get();
	return (w.ws_col);
}
