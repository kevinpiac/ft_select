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

/* rendering style */
# define COL_SIZE 10
# define LINE_SIZE 2

/* keystrokes listener */
# define IS_ARROW(first, second) (first == 27 && second == 79)
# define IS_KEY_LEFT(k) (k == 68)
# define IS_KEY_UP(k) (k == 65)
# define IS_KEY_RIGHT(k) (k == 67)
# define IS_KEY_DOWN(k) (k == 66)
# define IS_SPACE(k) (k == 32)
# define IS_ENTER(k) (k == 10)
# define IS_ESC(k) (k == 27)

/*
** ARG.C
*/
// revoir ici pour plus de coherence.
# define ARG_MODE_SELECTED 1
# define ARG_MODE_POINTED 2
# define ARG_MODE_NORMAL 0
# define ARG_IS_SELECTED(mode) (mode & ARG_MODE_SELECTED)
# define ARG_IS_POINTED(mode) ((mode >> 1))

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
int					arglist_get_current_index(t_arglist *list);

void				arg_select(t_arglist *list);


/*
** TERM.C
*/

int					term_init_data(void);
int					term_init_config(struct termios *termios);
int					term_out(int c);
void				term_restore(struct termios *termios);

/*
** CMD.C
*/

void				cmd_put(char *termcap);
void				cmd_goto(int col, int row);

/*
** SIZE.C
*/

struct winsize		size_get(void);
int					size_get_col(void);
int					size_get_row(void);
void				size_put(struct winsize);
int					size_calculate(t_arglist *list);

/*
** LISTENER.C
*/

void				listener_keystroke(t_arglist *list, struct termios *old_c);

/*
** MOVE.C
*/

void			move_right(t_arglist *list);
void			move_left(t_arglist *list);
void			move_up(t_arglist *list);
void			move_down(t_arglist *list);

/*
** SIGNAL
*/

void 			signal_handler(void);

#endif
