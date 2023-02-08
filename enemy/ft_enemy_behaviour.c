/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_behaviour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:40:42 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 10:34:30 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	ft_enemy_behaviour(t_game *game)
{
	int	i;
	int	en_x;
	int	en_y;

	i = 0;
	en_y = game->enemy->enemy_pos->y;
	en_x = game->enemy->enemy_pos->x;
	if (game->map[en_y][en_x] == 'P')
	{
		ft_printf("You Lose :-(((( !!!!\n");
		ft_close(game);
	}
	if (game->map[en_y][en_x + game->pov_en] != '1'
			&& game->map[en_y][en_x + game->pov_en] != 'C' )
	{
		if (game->map[en_y][en_x + game->pov_en] == '0')
		{	
			game->map[en_y][en_x + game->pov_en] = 'K';
			game->map[en_y][en_x] = '0';
		}
		game->enemy->enemy_pos->x += game->pov_en;
		en_x += game->pov_en;
		if (game->map[en_y][en_x + game->pov_en] == '1'
			|| game->map[en_y][en_x + game->pov_en] == 'C')
			game->pov_en = -(game->pov_en);
	}
	return (0);
}
