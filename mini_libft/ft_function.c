/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:27:52 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/08 16:31:34 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	char	*ptr;

	if (nmeb == SIZE_MAX && size == SIZE_MAX)
		return (0);
	ptr = malloc((nmeb * size));
	if (!ptr)
		return (0);
	ft_bzero(ptr, (nmeb * size));
	return ((void *) ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = ft_calloc(ft_strlen((char *)s) + 1, sizeof (char));
	if (!s2)
		return (0);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}

void	ft_bzero(void *str, size_t n)
{
	str = ft_memset(str, '\0', n);
	return ;
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (str);
}
