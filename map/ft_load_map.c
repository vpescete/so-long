/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:35:22 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/04 11:10:26 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../window/so_long.h"
#include "../get_next_line/get_next_line.h"

char	**ft_load_map(char *map_name)
{
	char	**map;
	int		count;
	int		fd;
	int		i;

	i = 1;
	count = ft_map_height(map_name);
	map = malloc(count * sizeof(char *));
	fd = open(map_name, O_RDONLY);
	map[0] = get_next_line(fd);
	map[0][ft_strlen(map[0]) - 1] = '\0';
	while (i < count)
	{
		map[i] = get_next_line(fd);
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
	close(fd);
	return (map);
}

int	ft_map_height(char *map_name)
{
	int	fd;
	int	count;

	count = 0;
	fd = open (map_name, O_RDONLY);
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
}

void	ft_charge_map_on_screen(char **map, int count, t_textures *textures, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, textures->wall, j * 64, i * 64);
			if (map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, textures->background, j * 64, i * 64);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, textures->escape, j * 64, i * 64);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, textures->player, j * 64, i * 64);
			j++;
		}
		i++;
	}
}	
