/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:57:22 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/20 16:57:24 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int		test(char *tmp, int n)
{
	int		i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (ft_isdigit(tmp[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atoi(tmp) < 1 || ft_atoi(tmp) > 3)
		return (0);
	if (ft_atoi(tmp) > n)
		return (0);
	return (1);
}

void	print_lol(int min)
{
	ft_putstr("\033[31mMap after computer match");
	ft_putstr(" (-");
	ft_putnbr(min);
	ft_putstr("):\033[0m\n");
}

int		dop(int *map, int *size, char **tmp)
{
	map[*size] -= ft_atoi(*tmp);
	free(*tmp);
	if (map[0] == 0)
		return (1);
	ft_putstr("\033[32mMap after player match:\033[0m\n");
	print_map(map, *size);
	if (map[*size] == 0)
		(*size)--;
	return (0);
}

void	dop2(int map, int *size)
{
	ft_putstr("\033[47m\033[34mEnter ");
	if (map >= 3)
		ft_putstr("digit between 1 and 3:\033[0m\n");
	else if (map == 2)
		ft_putstr("digit between 1 and 2:\033[0m\n");
	else
		ft_putstr("1:\033[0m\n");
	if (map == 0)
		(*size)--;
}

int		algo(int *map, int size)
{
	char	*tmp;
	int		min;

	tmp = NULL;
	print_map(map, size);
	while (1)
	{
		dop2(map[size], &size);
		get_next_line(1, &tmp);
		if (test(tmp, map[size]) == 1 && ft_atoi(tmp) <= map[size])
		{
			if (dop(map, &size, &tmp) == 1)
				return (1);
			map[size] -= (min = minus(map[size], (size == 0) ? 0 :
				map[size - 1], (size < 2) ? 0 : map[size - 2], ft_atoi(tmp)));
			if (map[0] == 0)
				return (0);
			if (map[size] == 0)
				size--;
			print_lol(min);
			print_map(map, size);
		}
		else
			free(tmp);
	}
}
