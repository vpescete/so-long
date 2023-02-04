/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:06:31 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/04 13:52:34 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*ft_load_game(t_textures *textures, void *mlx)
{
	t_game *game;
	
	game = malloc(1 * sizeof(t_game));
	game->images = textures;
	return (game);
}

t_textures	*ft_load_img(void *mlx)
{
	int	w;
	int	h;
	t_textures *images;
	
	
	w = 64;
	h = 64;
	images = malloc(1 * sizeof(t_textures));
	images->mlx = mlx;
	images->background = mlx_xpm_file_to_image(images->mlx,
			"src/xpm/background/sprite_0.xpm", &w, &h);
	images->wall = mlx_xpm_file_to_image(mlx,
			"src/xpm/wall/Wall_sprite0.xpm", &w, &h);
	images->escape = mlx_xpm_file_to_image(mlx,
			"src/xpm/escape/Escape_Sprite06.xpm", &w, &h);
	images->player = mlx_xpm_file_to_image(mlx,
			"src/xpm/player/sprite_dino0.xpm", &w, &h);
	return (images);
}