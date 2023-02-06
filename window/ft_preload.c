/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preload.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:28:21 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/06 19:01:21 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

t_game	*ft_preload(char *map_name, t_game *game, void *mlx)
{
	char	**map;
	int		count;

	game = malloc(sizeof(t_game));
	game->images = malloc(sizeof(t_textures));
	game->mlx = mlx;
	game->map = ft_load_map(map_name);
	game->count = ft_map_height(map_name);
	game->index = 0;
	game->widht	= 64;
	game->height = 64;
	game->counter = 0;
	game->vector = malloc(sizeof(t_vector));
	game->vect_exit = malloc(sizeof(t_vector));
	game->color = create_trgb(0, 0, 0, 0);
	game->pov = 0;
	gettimeofday(&(game->curr_tm), NULL);
	ft_load_img(game);
	ft_load_obj(game);
	return (game);
}
