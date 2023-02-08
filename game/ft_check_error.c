/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:37:29 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 19:39:13 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_error(int ac, char **av)
{
	size_t	len;

	if (ac != 2)
	{
		ft_printf("Error\nYou didn't pass any map !\n");
		exit(0);
	}
	len = ft_strlen(av[1]);
	if (!(check_ber_ext(av[1], len)))
	{
		ft_printf("Error\nCheck that your map is a .ber file\n");
		exit(0);
	}
}

int	check_ber_ext(char *av, size_t len)
{
	if (av[len - 1] == 'r' && av[len - 2] == 'e'
		&& av[len - 3] == 'b' && av[len - 4] == '.')
		return (1);
	return (0);
}
