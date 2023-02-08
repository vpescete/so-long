/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winscreen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:50:00 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/06 21:21:25 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

void	ft_winscreen(t_game *game)
{
	int	h;
	int	w;

	h = ((game->count * 64) / 2) - (32 / 2);
	w = ((ft_strlen(game->map[0]) * 64) / 2) - (96 / 2);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
				"src/xmp/Win/WinScreen_0.xpm", w, h);
}