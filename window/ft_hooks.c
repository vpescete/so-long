/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:29:30 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/05 18:36:02 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

void	ft_close(t_game *vars)
{
	// free(vars->object);
	free(vars->images);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free(vars);
	exit(0);
}

void	ft_move_right(t_game *vars)
{
	if (vars->map[vars->vector->y][vars->vector->x + 1] == 'C')
	{
		vars->coins_collected++;
		vars->map[vars->vector->y][vars->vector->x + 1] = 'P';
		vars->map[vars->vector->y][vars->vector->x] = '0';
	}
	if (vars->map[vars->vector->y][vars->vector->x + 1] == '0'
		|| vars->map[vars->vector->y - 1][vars->vector->x] == 'E')
	{
		vars->map[vars->vector->y][vars->vector->x + 1] = 'P';
		vars->map[vars->vector->y][vars->vector->x] = '0';
	}
}

void	ft_move_left(t_game *vars)
{
	if (vars->map[vars->vector->y][vars->vector->x - 1] == 'C')
	{
		vars->coins_collected++;
		vars->map[vars->vector->y][vars->vector->x - 1] = 'P';
		vars->map[vars->vector->y][vars->vector->x] = '0';
	}
	if (vars->map[vars->vector->y][vars->vector->x - 1] == '0'
		|| vars->map[vars->vector->y - 1][vars->vector->x] == 'E')
	{
		vars->map[vars->vector->y][vars->vector->x - 1] = 'P';
		vars->map[vars->vector->y][vars->vector->x] = '0';
	}
}

void	ft_move_up(t_game *vars)
{
	if (vars->map[vars->vector->y + 1][vars->vector->x] == 'C')
	{
		vars->coins_collected++;
		vars->map[vars->vector->y + 1][vars->vector->x] = 'P';
		vars->map[vars->vector->y][vars->vector->x] = '0';
	}
	if (vars->map[vars->vector->y + 1][vars->vector->x] == '0'
		|| vars->map[vars->vector->y - 1][vars->vector->x] == 'E')
	{
		vars->map[vars->vector->y + 1][vars->vector->x] = 'P';
		vars->map[vars->vector->y][vars->vector->x] = '0';
	}
}

void	ft_move_down(t_game *vars)
{
	if (vars->map[vars->vector->y - 1][vars->vector->x] == 'C')
	{
		vars->coins_collected++;
		vars->map[vars->vector->y - 1][vars->vector->x] = 'P';
		vars->map[vars->vector->y][vars->vector->x] = '0';
	}
	if (vars->map[vars->vector->y - 1][vars->vector->x] == '0'
		|| vars->map[vars->vector->y - 1][vars->vector->x] == 'E')
	{
		vars->map[vars->vector->y - 1][vars->vector->x] = 'P';
		vars->map[vars->vector->y][vars->vector->x] = '0';
	}
}
