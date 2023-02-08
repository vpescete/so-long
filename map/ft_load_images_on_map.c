/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_images_on_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:17:14 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 11:47:02 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

void	ft_check_w_b_k(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->background, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->wall, j * 64, i * 64);
	}
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->background, j * 64, i * 64);
	if (game->map[i][j] == 'K')
	{	
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->background, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemy->img, j * 64, i * 64);
	}
}

void	ft_check_e_p_c(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E')
	{
		game->vect_exit->x = j;
		game->vect_exit->y = i;
		game->map[i][j] = '0';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->background, j * 64, i * 64);
	}
	if (game->map[i][j] == 'P')
	{
		game->vector->x = j;
		game->vector->y = i;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->background, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->player[game->pov], j * 64, i * 64);
	}
	if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->background, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->collectible[game->index], j * 64, i * 64);
	}
}
