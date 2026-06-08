/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:35:03 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/08 17:55:33 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//Checks whether the input file ends with the .cub extension.
//The subject requires the scene description file to use this format.

void	check_extension(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 5)
		error_exit("Invalid file extension");
	if (filename[i - 4] != '.'
		|| filename[i - 3] != 'c'
		|| filename[i - 2] != 'u'
		|| filename[i - 1] != 'b')
		error_exit("Invalid file extension");
}
