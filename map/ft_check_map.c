/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:52:29 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/03 16:52:33 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window/so_long.h"

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

int	check_wall(char **map, int count)
{
	int	i;
	int	len;

	i = 0;
	if (ft_check_lenline(map, count) == 1)
	{
		len = ft_strlen(map[0]);
		while (map[0][i] == '1' && map[count - 1][i] == '1' && i < ft_strlen(map[0]))
			i++;
		if (i != ft_strlen(map[0]))
			return (0);
		i = 0;
		while (i < count)
		{
			if (!(map[i][0] == '1' && map[i][len - 1] == '1'))
				return (0);
			i++;
		}
		if (i != count)
			return (0);
	}
	return (1);
}
