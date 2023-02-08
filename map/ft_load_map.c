/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:35:22 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/07 20:20:42 by vpescete         ###   ########.fr       */
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

void	ft_charge_map_on_screen(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->count)
	{
		j = 0;
		while (j < ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == '1' || game->map[i][j] == '0'
				|| game->map[i][j] == 'K')
				ft_check_w_b_k(game, i, j);
			else if (game->map[i][j] == 'E'
					|| game->map[i][j] == 'P' || game->map[i][j] == 'C')
				ft_check_e_p_c(game, i, j);
			j++;
		}
		i++;
	}
	if (game->coins_collected == game->object->collectibles)
		ft_put_img_to_win(game);
	mlx_string_put(game->mlx, game->mlx_win, 20, 20, game->color,
		ft_itoa(game->counter));
}	

void	ft_put_img_to_win(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->escape[game->index], game->vect_exit->x * 64,
			game->vect_exit->y * 64);
}
