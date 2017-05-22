/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:10:11 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/20 15:10:13 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM_H
# define ALUM_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_alum
{
	int			row;
	void		*next;
}				t_alum;

int				algo(int *map, int size);
void			print_map(int *map, int size);
void			ft_lstrev_alum(t_alum **alst);
t_alum			*ft_newalum(int i, char **text);
void			ft_add_list(t_alum **list, t_alum *new);
void			winner(int *array, int array_count, t_alum *list);
int				minus(int map, int map1, int map2, int user);
int				error_sign(void);
t_alum			*delete_list(t_alum *list, char **text);

#endif
