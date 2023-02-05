/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:52:29 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/05 19:01:55 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	ft_check_lenline(char **map, int count)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (i < count)
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char **map, int count)
{
	int	i;
	int	len;

	i = 0;
	if (ft_check_lenline(map, count) == 1)
	{
		len = ft_strlen(map[0]);
		while (map[0][i] == '1' && map[count - 1][i] == '1' && i < ft_strlen(map[0]))
			i++;
		if (i != ft_strlen(map[0]))
			return (0);
		i = 0;
		while (i < count)
		{
			if (!(map[i][0] == '1' && map[i][len - 1] == '1'))
				return (0);
			i++;
		}
		if (i != count)
			return (0);
	}
	return (1);
}

int	check_min_requires(char **map, int count, t_game *game)
{
	int			i;
	int			j;

	i = 0;
	game->object = (t_object *)malloc(3 * sizeof(t_object));
	if (!game->object)
		return (0);
	
	game->object->collectibles = 0;
	game->object->escape = 0;
	game->object->player = 0;
	game->coins_collected = 0;
	while (i < count)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'P')
				game->object->player++;
			else if (map[i][j] == 'C')
				game->object->collectibles++;
			else if (map[i][j] == 'E')
				game->object->escape++;
			j++;
		}
		i++;
	}
	ft_printf("player: %u, coin: %u, escape: %u\n", game->object->player, game->object->collectibles,  game->object->escape);
	if (game->object->player >= 1 && game->object->collectibles >= 1 && game->object->escape >= 1)
		return (1);
	return (0);
}

