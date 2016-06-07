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
# include <sys/ioctl.h>
# include <signal.h>

# define COL_SIZE 10
# define LINE_SIZE 2

/*
** ARG.C
*/

# define ARG_MODE_SELECTED 1
# define ARG_MODE_POINTED 2
# define ARG_MODE_NORMAL 0
# define ARG_IS_SELECTED(mode) (mode &= ARG_MODE_SELECTED)
# define ARG_IS_POINTED(mode) (mode &= ARG_MODE_POINTED)

typedef struct 		s_arg
{
	char			*name;
	size_t			len;
	int				mode;
}					t_arg;

t_arg				*arg_new(char *name, int mode);
void				arg_del(void *this);
void				arg_print(void *this);

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
void				arglist_render(t_arglist *this);

/*
** TERM.C
*/

int					term_init_data(void);
int					term_init_config(struct termios *termios);
int					term_out(int c);

/*
** CMD.C
*/

void				cmd_put(char *termcap);
void				cmd_goto(int col, int line);

/*
** SIZE.c
*/

struct winsize		size_get(void);
int					size_get_x(void);
int					size_get_y(void);
void				size_put(struct winsize);

#endif
