/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isemptyline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 00:16:26 by achoukri          #+#    #+#             */
/*   Updated: 2025/10/03 00:22:22 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_empty_line(char *line)
{
	int	i;

	if (!line || line[0] == '\0')
		return (1);
	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}
