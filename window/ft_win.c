/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:28:21 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 10:20:35 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

void	ft_win(t_game *game)
{
	int	i;

	i = 0;
	if ((game->coins_collected == game->object->collectibles)
		&& game->vector->x == game->vect_exit->x
		&& game->vector->y == game->vect_exit->y)
	{
		ft_printf("You win MF !!\n");
		exit(0);
		// ft_close(game);
	}
}
