/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:06:31 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/04 12:10:46 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_game(t_game *game, t_textures *images, void *mlx)
{
	int		*w;
	int		*h;
	void	*mlx_win;

	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1920, 1080, "so_long");
	game->images->background = mlx_xpm_file_to_image(game->mlx,
			"src/xpm/background/sprite_0.xpm", w, h);
	game->images->wall = mlx_xpm_file_to_image(game->mlx,
			"src/xpm/wall/Wall_sprite0.xpm", w, h);
	game->images->escape = mlx_xpm_file_to_image(game->mlx,
			"src/xpm/escape/Escape_Sprite06.xpm", w, h);
	game->images->player = mlx_xpm_file_to_image(game->mlx,
			"src/xpm/player/sprite_dino0.xpm", w, h);
}
