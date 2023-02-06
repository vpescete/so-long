/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:55:57 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/06 15:54:12 by vpescete         ###   ########.fr       */
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
	if (res >= 100)
		game->curr_tm = now;
	return (res);
}

int	ft_next_frame(t_game *game)
{
	if (ft_gettimestamp(game) >= 100)
	{
		if (game->index == 11)
			game->index = 0;
		else
			game->index++;
		ft_charge_map_on_screen(game);
	}
	return (0);
}