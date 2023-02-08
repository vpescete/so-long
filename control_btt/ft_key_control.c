/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:41:52 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 19:53:33 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	ft_key_control(int kc, t_game *vars)
{
	int	x;
	int	y;

	x = vars->vector->x;
	y = vars->vector->y;
	if (kc == 53 || kc == 124 || kc == 123 || kc == 125 || kc == 126)
	{	
		if (kc == 53)
			ft_close(vars);
		if (kc == 124)
			ft_move_right(vars);
		if (kc == 123)
			ft_move_left(vars);
		if (kc == 125)
			ft_move_up(vars);
		if (kc == 126)
			ft_move_down(vars);
		ft_charge_map_on_screen(vars);
		if (vars->vector->x != x || vars->vector->y != y)
			vars->counter++;
	}
	ft_win(vars);
	return (0);
}
