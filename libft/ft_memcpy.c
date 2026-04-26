/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:22:43 by eeravci           #+#    #+#             */
/*   Updated: 2025/10/22 17:48:06 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(const char *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

int	main(void)
{
	char	dest[25];
	char	src[] = "Hello my name is Enes.";

	printf("Before ft_memcpy()\nsrc: %s\ndest: %s\n", src, dest);
	ft_memcpy(dest, src, sizeof(src));
	printf("After ft_memcpy()\nsrc: %s\ndest: %s\n", src, dest);
}
