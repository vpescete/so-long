/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:29:30 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 19:52:21 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

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
	if (vars->map[vars->vector->y][vars->vector->x + 1] == 'K' )
	{
		ft_printf("You Lose :-(((( !!!!\n");
		ft_close(vars);
	}
	vars->pov = 0;
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
	if (vars->map[vars->vector->y][vars->vector->x - 1] == 'K' )
	{
		ft_printf("You Lose :-(((( !!!!\n");
		ft_close(vars);
	}
	vars->pov = 1;
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
	if (vars->map[vars->vector->y + 1][vars->vector->x] == 'K' )
	{
		ft_printf("You Lose :-(((( !!!!\n");
		ft_close(vars);
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
	if (vars->map[vars->vector->y - 1][vars->vector->x] == 'K' )
	{
		ft_printf("You Lose :-(((( !!!!\n");
		ft_close(vars);
	}
}
