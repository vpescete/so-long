/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:35:22 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/05 19:22:48 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

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

void	ft_base_layer(int count, int len, t_textures *textures, t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < len)
			mlx_put_image_to_window(game->mlx, game->mlx_win, textures->background, j * 64, i * 64);
		i++;
	}
}

void	ft_charge_map_on_screen(t_game *game)
{
	int	i;
	int	j;
	int	trigger;

	i = 0;
	while (i < game->count)
	{
		j = 0;
		while (j < ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->background, j * 64, i * 64);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->wall, j * 64, i * 64);
			}
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->background, j * 64, i * 64);
			if (game->map[i][j] == 'E')
			{
				game->vect_exit->x = j;
				game->vect_exit->y = i;
				game->map[i][j] = '0';
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->background, j * 64, i * 64);
			}
			if (game->map[i][j] == 'P')
			{
				game->vector->x = j;
				game->vector->y = i;
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->background, j * 64, i * 64);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->player, j * 64, i * 64);
			}
			if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->background, j * 64, i * 64);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->collectible, j * 64, i * 64);
			}
			
			// printf("coins_colleted: %d :: coins_on_map: %d\n", game->coins_collected, game->object->collectibles);		
			j++;
		}
		i++;
	}
	if (game->coins_collected == game->object->collectibles)
	{
		printf("x: %d :: y: %d\n", game->vect_exit->x, game->vect_exit->y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->escape, game->vect_exit->x * 64, game->vect_exit->y * 64);
	}
}	
