/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:11:32 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/04 13:11:36 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char		**map;
	int			count;
	void		*mlx;
	t_textures	*images;
	t_game		*game;

	if (ft_check_error(ac, av) == 0)
		return (0);
	map = ft_load_map(av[1]);
	count = ft_map_height(av[1]);
	if (check_wall(map, count) == 1)
		printf("checked wall !!!!\n");
	mlx = mlx_init();
	images = ft_load_img(mlx);
	game = ft_load_game(images, mlx);
	game->mlx_win = mlx_new_window(mlx, 1920, 1080, "Dino & Morty!");
	ft_charge_map_on_screen(map, count, images, game, mlx);
	mlx_loop(mlx);
}
