/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:49:24 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 19:50:56 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

static void	ft_free_struff(t_game *vars)
{
	mlx_destroy_image(vars->mlx, vars->images->wall);
	mlx_destroy_image(vars->mlx, vars->images->background);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free(vars->vector);
	free(vars->object);
	free(vars->vect_exit);
	free(vars->images);
}

void	ft_close(t_game *vars)
{
	int i;
	
	i = 0;
	while (i < vars->count)
		free(vars->map[i++]);
	free(vars->map);
	i = 0;
	while (i < 12)
	{
		if (i < 2)
			mlx_destroy_image(vars->mlx, vars->images->player[i]);
		mlx_destroy_image(vars->mlx, vars->images->escape[i]);
		mlx_destroy_image(vars->mlx, vars->images->collect[i]);
		i++;
	}
	ft_free_struff(vars);
	if (vars->count_en > 0)
	{
		mlx_destroy_image(vars->mlx, vars->enemy->img);
		free(vars->enemy->enemy_pos);
		free(vars->enemy);
	}
	free(vars);
	exit(0);
}
