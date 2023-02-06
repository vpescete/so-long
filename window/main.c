/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:11:32 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/06 17:40:30 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	main(int ac, char **av)
{
	void		*mlx;
	t_game		*game;

	if (ft_check_error(ac, av) == 0)
		return (0);
	mlx = mlx_init();
	game = ft_preload(av[1], game, mlx);
	check_wall(game->map, game->count);
	ft_check_rect(game);
	if (check_min_requires(game) == 0)
		exit(0);
	game->mlx_win = mlx_new_window(mlx, ft_strlen(game->map[0]) * 64,
			game->count * 64, "Dino & Morty!");
	mlx_loop_hook(game->mlx, ft_next_frame, game);
	mlx_hook(game->mlx_win, 2, 0, ft_key_control, game);
	ft_charge_map_on_screen(game);
	// mlx_string_put(game->mlx, game->mlx_win, 32, 32, game->color,
	// 	ft_itoa(game->coins_collected));
	mlx_loop(mlx);
}
