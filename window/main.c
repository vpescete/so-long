/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:11:32 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/05 19:14:46 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

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
	if (check_wall(map, count) == 0)
	{
		exit(0);
	}
		ft_printf("checked wall !!!!\n");
	mlx = mlx_init();
	images = ft_load_img(mlx);
	game = ft_load_game(images, mlx);
	game->mlx = mlx;
	game->map = map;
	game->count = count;
	if (check_min_requires(map, count, game) == 1)
		ft_printf("Check the minimun requires !!!\n");
	game->mlx_win = mlx_new_window(mlx, ft_strlen(map[0]) * 64, count * 64, "Dino & Morty!");
	// ft_base_layer(count, ft_strlen(map[0]), images, game);
	mlx_key_hook (game->mlx_win, ft_key_control, game);
	game->vector = malloc(sizeof(t_vector));
	game->vect_exit = malloc(sizeof(t_vector));
	ft_charge_map_on_screen(game);
	mlx_loop(mlx);
}
