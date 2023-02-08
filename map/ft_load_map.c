/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:35:22 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 19:40:14 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

char	**ft_load_map(char *map_name, t_game *game)
{
	char	**map;
	int		fd;
	int		i;
	char	*string;

	i = 0;
	map = malloc(game->count * sizeof(char *));
	fd = open(map_name, O_RDONLY);
	string = get_next_line(fd);
	while (i < game->count)
	{
		map[i] = ft_strdup(string);
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		free(string);
		string = get_next_line(fd);
		i++;
	}
	free(string);
	close(fd);
	return (map);
}

int	ft_map_height(char *map_name)
{
	int		fd;
	int		count;
	char	*string;

	count = 0;
	fd = open (map_name, O_RDONLY);
	string = get_next_line(fd);
	while (string)
	{
		count++;
		free(string);
		string = get_next_line(fd);
	}
	free(string);
	close(fd);
	return (count);
}

void	ft_charge_map_on_screen(t_game *game)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	string = ft_itoa(game->counter);
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
	if (game->coins_collected == game->object->collects)
		ft_put_img_to_win(game);
	mlx_string_put(game->mlx, game->mlx_win, 20, 20, game->color, string);
	free(string);
}	

void	ft_put_img_to_win(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->images->escape[game->index], game->vect_exit->x * 64,
		game->vect_exit->y * 64);
}
