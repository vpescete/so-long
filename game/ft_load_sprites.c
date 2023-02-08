/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:06:31 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/07 20:01:11 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_obj(t_game *game)
{
	game->object = (t_object *)malloc(sizeof(t_object));
	game->object->collectibles = 0;
	game->object->escape = 0;
	game->object->player = 0;
	game->coins_collected = 0;
}

void	ft_load_img(t_game *game)
{
	game->images->background = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/background/ground.xpm", &game->widht, &game->height);
	game->images->wall = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/wall/Wall_sprite0.xpm", &game->widht, &game->height);
	ft_load_frame_player(game);
	ft_load_frame_coin(game);
	ft_load_frame_escape(game);
}

void	ft_load_frame_player(t_game *game)
{
	game->images->player[0] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/player/dino0.xpm", &game->widht, &game->height);
	game->images->player[1] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/player/dino0left.xpm", &game->widht, &game->height);
}

void	ft_load_frame_escape(t_game *game)
{
	game->images->escape[0] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite00.xpm", &game->widht, &game->height);
	game->images->escape[1] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite01.xpm", &game->widht, &game->height);
	game->images->escape[2] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite02.xpm", &game->widht, &game->height);
	game->images->escape[3] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite03.xpm", &game->widht, &game->height);
	game->images->escape[4] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite04.xpm", &game->widht, &game->height);
	game->images->escape[5] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite05.xpm", &game->widht, &game->height);
	game->images->escape[6] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite06.xpm", &game->widht, &game->height);
	game->images->escape[7] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite07.xpm", &game->widht, &game->height);
	game->images->escape[8] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite08.xpm", &game->widht, &game->height);
	game->images->escape[9] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite09.xpm", &game->widht, &game->height);
	game->images->escape[10] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite10.xpm", &game->widht, &game->height);
	game->images->escape[11] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/escape/Escape_Sprite11.xpm", &game->widht, &game->height);
}

void	ft_load_frame_coin(t_game *game)
{
	game->images->collectible[0] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite00.xpm", &game->widht, &game->height);
	game->images->collectible[1] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite01.xpm", &game->widht, &game->height);
	game->images->collectible[2] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite02.xpm", &game->widht, &game->height);
	game->images->collectible[3] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite03.xpm", &game->widht, &game->height);
	game->images->collectible[4] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite04.xpm", &game->widht, &game->height);
	game->images->collectible[5] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite05.xpm", &game->widht, &game->height);
	game->images->collectible[6] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite06.xpm", &game->widht, &game->height);
	game->images->collectible[7] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite07.xpm", &game->widht, &game->height);
	game->images->collectible[8] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite08.xpm", &game->widht, &game->height);
	game->images->collectible[9] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite09.xpm", &game->widht, &game->height);
	game->images->collectible[10] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite10.xpm", &game->widht, &game->height);
	game->images->collectible[11] = mlx_xpm_file_to_image(game->mlx,
			"src/xmp/collectible/Coin_Sprite11.xpm", &game->widht, &game->height);
}
