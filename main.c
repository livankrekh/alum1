/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:06:32 by liabanzh          #+#    #+#             */
/*   Updated: 2017/05/20 15:06:50 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

size_t			ft_lstcount_alum(t_alum *lst)
{
	size_t i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static int		test(char *tmp)
{
	int		i;

	i = 0;
	if (tmp == NULL || tmp[0] == '\0')
		return (0);
	while (tmp[i] != '\0')
	{
		if (ft_isdigit(tmp[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atoi(tmp) > 10000 || ft_atoi(tmp) <= 0)
		return (0);
	return (1);
}

t_alum			*get_stdin(int fd)
{
	t_alum	*list;
	char	*text;

	list = NULL;
	while (get_next_line(fd, &text) == 1)
	{
		if (fd == 0 && text[0] == '\0')
			break ;
		if (test(text) == 0)
			return (delete_list(list, &text));
		ft_add_list(&list, ft_newalum(ft_atoi(text), &text));
	}
	if (fd == 0)
		free(text);
	ft_lstrev_alum(&list);
	if (fd > 2)
		close(fd);
	return (list);
}

int				make_mas(int **array, t_alum *map)
{
	int		i;
	int		t;
	t_alum	*check;

	check = map;
	i = ft_lstcount_alum(check);
	*array = (int*)malloc(sizeof(int) * i);
	t = 0;
	while (t < i && map)
	{
		(*array)[t] = map->row;
		map = map->next;
		t++;
	}
	return (i);
}

int				main(int argc, char **argv)
{
	t_alum		*map;
	int			file_descr;
	int			*array;
	int			array_count;

	map = NULL;
	file_descr = 0;
	if (argc > 3)
		return (error_sign());
	if (argc >= 1)
	{
		if (argc == 2 && (file_descr = open(argv[1], O_RDONLY)) == -1)
			return (error_sign());
		if ((map = get_stdin(file_descr)) == NULL)
			return (error_sign());
	}
	array_count = make_mas(&array, map);
	winner(array, array_count, map);
	return (0);
}
