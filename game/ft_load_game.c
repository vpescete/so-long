/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:06:31 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/05 17:02:42 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*ft_load_game(t_textures *textures, void *mlx)
{
	t_game *game;
	
	game = malloc(1 * sizeof(t_game));
	game->images = textures;
	game->mlx = mlx;
	return (game);
}

t_textures	*ft_load_img(void *mlx)
{
	int			w;
	int			h;
	t_textures	*images;
	
	w = 64;
	h = 64;
	images = malloc(1 * sizeof(t_textures));
	images->mlx = mlx;
	images->background = mlx_xpm_file_to_image(images->mlx,
			"src/xmp/background/ground.xpm", &w, &h);
	images->wall = mlx_xpm_file_to_image(mlx,
			"src/xmp/wall/Wall_sprite0.xpm", &w, &h);
	images->escape = mlx_xpm_file_to_image(mlx,
			"src/xmp/escape/Escape_Sprite06.xpm", &w, &h);
	images->player = mlx_xpm_file_to_image(mlx,
			"src/xmp/player/sprite_dino0.xpm", &w, &h);
	images->collectible = mlx_xpm_file_to_image(mlx,
			"src/xmp/collectible/Coin_sprite00.xpm", &w, &h);
	return (images);
}