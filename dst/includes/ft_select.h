/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:33:27 by kpiacent          #+#    #+#             */
/*   Updated: 2016/05/24 09:39:48 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/includes/libft.h"
# include <termios.h>
# include <curses.h>
# include <term.h>

/*
** ARG.C
*/

typedef struct 		s_arg
{
	char			*name;
	size_t			len;
	int				mode; //create macro for underlined, selected, passive
}					t_arg;

t_arg				*arg_new(char *name);
void				arg_del(void *this);

/*
** ARGLIST.C
*/

typedef struct		s_arglist
{
	t_vector		*args;
	size_t			biggest;
	// add every usefull function pointer bellow...
}					t_arglist;

t_arglist			*arglist_new(int ac, char **av);
void				arglist_del(t_arglist *this);

/*
** TERM.C
*/

int					term_init_data(void);
int					term_init_config(struct termios *termios);

#endif
