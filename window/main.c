/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:11:32 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 19:30:59 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	main(int ac, char **av)
{
	void		*mlx;
	t_game		*game;

	ft_check_error(ac, av);
	mlx = mlx_init();
	game = ft_preload_map(av[1], game);
	if (check_min_requires(game) == 0)
	{
		ft_printf("Error\nSomething is missing on the map !\n");
		exit(0);
	}
	ft_preload(game, mlx);
	check_wall(game->map, game->count);
	ft_check_rect(game);
	game->mlx_win = mlx_new_window(mlx, ft_strlen(game->map[0]) * 64,
			game->count * 64, "Dino & Morty!");
	mlx_loop_hook(game->mlx, ft_next_frame, game);
	ft_charge_map_on_screen(game);
	mlx_hook(game->mlx_win, 17, 0, end_game, game);
	mlx_hook(game->mlx_win, 2, 0, ft_key_control, game);
	mlx_loop(mlx);
}
