/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:55:57 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 19:54:32 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	ft_gettimestamp(t_game *game)
{
	struct timeval	now;
	int				res;

	gettimeofday(&now, NULL);
	res = (((now.tv_sec * 1000) + (now.tv_usec / 1000))
			- ((game->curr_tm.tv_sec * 1000) + (game->curr_tm.tv_usec / 1000)));
	if (res >= 140)
		game->curr_tm = now;
	return (res);
}

int	ft_next_frame(t_game *game)
{
	if (ft_gettimestamp(game) >= 140)
	{
		if (game->index == 11)
			game->index = 0;
		else
			game->index++;
		if (game->count_en > 0)
			ft_enemy_behaviour(game);
		ft_charge_map_on_screen(game);
	}
	if ((game->count_en > 0) && game->enemy->enemy_pos->x == game->vector->x
		&& game->enemy->enemy_pos->y == game->vector->y)
	{
		ft_printf("You Lose !!\n");
		ft_close(game);
	}
	return (0);
}
