/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:01:13 by hmoubal           #+#    #+#             */
/*   Updated: 2022/01/15 00:42:03 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(t_map *map, int map_height)
{
	int	i;

	i = 0;
	while (i < map_height)
	{
		free(map->map[i]);
		i++;
	}
	map->map = NULL;
}

int	key_hook(int keycode, t_map *map)
{
	t_srcs	srcs;

	ft_init(&srcs, map);
	ft_keyhook(&srcs, map, keycode);
	return (0);
}

int	ft_close(t_map *map)
{
	ft_free(map, map->height);
	exit(1);
	return (0);
}

int	ft_so_long(t_map *map, t_srcs *srcs)
{
	ft_create_win(map);
	ft_init(srcs, map);
	ft_fillmap(srcs, map);
	// (void)srcs;
	mlx_hook(map->win, 2, 0, &key_hook, map);
	//mlx_loop_hook(map->mlx, &ft_animation, map);
	mlx_hook(map->win, 17, 0, &ft_close, NULL);
	mlx_loop(map->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_cont	more;
	t_map	map;
	t_srcs	srcs;

	if (ac == 2)
	{
		if (ft_ber(av[1]) == 0)
			return (0);
		ft_init2(&map, &more, &srcs);
		ft_fill_size(av[1], &map);
		if (ft_fill(av[1], &map) == 0)
			return (0);
		if (ft_checksize(&map) == 0)
			return (0);
		if (ft_checkmap(&map, &more) == 0)
			return (0);
		// ft_create_win(&map);
		// ft_init(&srcs, &map);
		// ft_fillmap(&srcs, &map);
		ft_so_long(&map, &srcs);
	}
	else
		ft_putstr("error syntaxe\n");
	return (0);
}
