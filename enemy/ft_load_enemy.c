/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:15:52 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 19:47:25 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

void	ft_load_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->enemy = malloc(sizeof(t_enemy));
	game->enemy->enemy_pos = malloc(sizeof(t_vector));
	while (i < game->count)
	{
		j = 0;
		while (j < ft_strlen(game->map[0]))
		{
			if (game->map[i][j] == 'K')
			{
				game->enemy->enemy_pos->x = j;
				game->enemy->enemy_pos->y = i;
				game->enemy->img = mlx_xpm_file_to_image(game->mlx,
						"src/xmp/enemy/enemy.xpm", &game->widht, &game->height);
			}
			j++;
		}
		i++;
	}
}
