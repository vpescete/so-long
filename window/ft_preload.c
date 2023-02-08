/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preload.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:28:21 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 19:36:57 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

t_game	*ft_preload_map(char *map_name, t_game *game)
{
	game = malloc(sizeof(t_game));
	game->count = ft_map_height(map_name);
	game->map = ft_load_map(map_name, game);
	ft_load_obj(game);
	game->count_en = 0;
	return (game);
}

void	ft_preload(t_game *game, void *mlx)
{
	game->images = malloc(sizeof(t_textures));
	game->mlx = mlx;
	game->index = 0;
	game->widht = 64;
	game->height = 64;
	game->counter = 0;
	game->vector = malloc(sizeof(t_vector));
	game->vect_exit = malloc(sizeof(t_vector));
	game->color = create_trgb(0, 0, 0, 0);
	game->pov = 0;
	game->win_x = 96;
	game->win_y = 32;
	if (game->count_en > 0)
	{
		ft_load_enemy(game);
		game->pov_en = 1;
	}
	gettimeofday(&(game->curr_tm), NULL);
	ft_load_img(game);
}
