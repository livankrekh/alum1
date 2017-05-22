/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 14:44:58 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/21 14:45:00 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int		lets_lose(int map, int user)
{
	int		super;

	super = 0;
	if (map <= 3)
		return (map);
	else
	{
		super = (((map - 4) / 4) * 4) + 4;
		return ((map - super == 0) ? user : map - super);
	}
}

int		minus(int map, int map1, int map2, int user)
{
	int		super;
	int		super2;

	super = (((map1 - 5) / 4) * 4) + 5;
	if (map2 != 0)
		super2 = (((map2 - 5) / 4) * 4) + 5;
	else
		super2 = -1;
	if (super == map1 && super2 != map2)
		return (lets_lose(map, user));
	if (map == 3)
		return (2);
	else if (map <= 2)
		return (1);
	else if (map == 4)
		return (3);
	else if (map == 6)
		return (1);
	else if (map == 7)
		return (2);
	else
	{
		super = (((map - 5) / 4) * 4) + 5;
		return ((map - super == 0) ? user : map - super);
	}
}

t_alum	*delete_list(t_alum *list, char **text)
{
	t_alum	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = tmp->next;
		free(tmp);
	}
	free(text);
	text = NULL;
	return (NULL);
}

int		error_sign(void)
{
	ft_putstr("\033[31mERROR\033[0m\n");
	return (0);
}
