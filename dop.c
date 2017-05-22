/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:50:14 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/20 18:50:15 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

void	winner(int *array, int array_count, t_alum *list)
{
	t_alum	*tmp;

	if (algo(array, array_count - 1) == 1)
		ft_putstr("\033[41m You lose! \033[0m\n");
	else
		ft_putstr("\033[42m\033[30m You win! \033[0m\n");
	free(array);
	while (list != NULL)
	{
		tmp = list;
		list = tmp->next;
		free(tmp);
	}
}

void	print_map(int *map, int size)
{
	int		i;
	int		count;

	i = 0;
	while (i <= size)
	{
		count = 0;
		while (count < map[i])
		{
			ft_putstr("|");
			count++;
		}
		ft_putstr("\n");
		i++;
	}
}

t_alum	*ft_newalum(int i, char **text)
{
	t_alum	*alum;

	alum = (t_alum *)malloc(sizeof(t_alum));
	alum->row = i;
	alum->next = NULL;
	free(*text);
	return (alum);
}

void	ft_lstrev_alum(t_alum **alst)
{
	t_alum	*prev;
	t_alum	*cur;
	t_alum	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

void	ft_add_list(t_alum **list, t_alum *new)
{
	if (new)
	{
		if (!(*list))
			*list = new;
		else
		{
			new->next = *list;
			*list = new;
		}
	}
}
