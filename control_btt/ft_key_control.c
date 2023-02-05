/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:41:52 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/05 17:49:26 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int ft_key_control(int keycode, t_game *vars)
{
	if (keycode == 53)
		ft_close(vars);
	if (keycode == 124)
		ft_move_right(vars);
	if (keycode == 123)	
		ft_move_left(vars);
	if (keycode == 125)	
		ft_move_up(vars);
	if (keycode == 126)	
		ft_move_down(vars);
	ft_charge_map_on_screen(vars);
	// ft_printf("%d\n", keycode);
	return (0);
}
