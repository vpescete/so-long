/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:37:29 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/04 10:08:40 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_error(int ac, char **av)
{
	size_t	len;

	if (ac != 2)
		return (0);
	len = ft_strlen(av[1]);
	if (!(check_ber_ext(av[1], len)))
		return (0);
	return (1);
}

int	check_ber_ext(char *av, size_t len)
{
	if (av[len - 1] == 'r' && av[len - 2] == 'e'
		&& av[len - 3] == 'b' && av[len - 4] == '.')
	{
		printf("name map checked !!!\n");
		return (1);
	}
	printf("name map not checked :-(\n");
	return (0);
}