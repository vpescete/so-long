/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:28:21 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/06 19:36:17 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

void	ft_win(t_game *game)
{
	int	i;

	i = 0;
	if ((game->coins_collected == game->object->collectibles)
		&& game->vector->x == game->vect_exit->x
		&& game->vector->y == game->vect_exit->y)
	{
		// mlx_put_image_to_window(game->mlx, game->mlx_win,
		// 	game->images->win_screen[0], (game->vect_exit->x - 1) * 64,
		// 	(game->vect_exit->y - 1) * 64);
		ft_printf("You win MF !!\n");
		free(game->object);
		while (i < 12)
		{
			mlx_destroy_image(game->mlx, game->images->escape[i]);
			mlx_destroy_image(game->mlx, game->images->collectible[i]);
			i++;
		}
		free(game->images);
		free(game->vect_exit);
		free(game->vector);
		free(game->map);
		mlx_destroy_window(game->mlx, game->mlx_win);
		free(game);
		exit(0);
	}
}
