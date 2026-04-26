/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:26:40 by eeravci           #+#    #+#             */
/*   Updated: 2025/10/22 17:42:33 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*arr;

	arr = (unsigned char *)s;
	while (n > 0)
	{
		*arr = (unsigned char)c;
		arr++;
		n--;
	}
	return (s);
}

int	main(void)
{
	char	str[22] = "hello my name is enes";

	printf("befor memset: %s\n", str);
	ft_memset(str, 'e', 0 * sizeof(char));
	printf("after memset: %s\n", str);
}
