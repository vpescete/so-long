/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:28:21 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/06 15:22:56 by vpescete         ###   ########.fr       */
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
