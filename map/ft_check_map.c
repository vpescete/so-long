/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:52:29 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 19:40:14 by vpescete         ###   ########.fr       */
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

void	check_wall(char **map, int count)
{
	int	i;
	int	len;

	i = 0;
	if (ft_check_lenline(map, count) == 1)
	{
		len = ft_strlen(map[0]);
		while (map[0][i] == '1' && map[count - 1][i] == '1'
			&& i < ft_strlen(map[0]))
			i++;
		if (i != ft_strlen(map[0]))
			exit(0);
		i = 0;
		while (i < count)
		{
			if (!(map[i][0] == '1' && map[i][len - 1] == '1'))
				exit(0);
			i++;
		}
		if (i != count)
			exit(0);
	}
}

int	check_min_requires(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < game->count)
	{
		j = 0;
		while (j < ft_strlen(game->map[i]))
		{
			ft_incrementer(game, i, j);
			j++;
		}
		i++;
	}
	if (game->object->player == 1 && game->object->collects >= 1
		&& game->object->escape == 1)
		return (1);
	return (0);
}

void	ft_incrementer(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		game->object->player++;
	else if (game->map[i][j] == 'C')
		game->object->collects++;
	else if (game->map[i][j] == 'E')
		game->object->escape++;
	else if (game->map[i][j] == 'K')
		game->count_en++;
	else if (game->map[i][j] != '1' && game->map[i][j] != '0')
		exit(0);
}

void	ft_check_rect(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->count)
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[0]))
		{
			ft_printf("Error\nThe map that you passed is not right\n");
			exit(0);
		}
		i++;
	}
}
