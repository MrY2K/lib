/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:02:54 by achoukri          #+#    #+#             */
/*   Updated: 2025/10/07 01:04:50 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char_array(char **arr)
{
	int	i;

	if (!arr)
	{
		ft_printf("Array is NULL :C\n");
		return ;
	}
	i = 0;
	while (arr[i] != NULL)
	{
		ft_printf("String[%d]: %s\n", i, arr[i]);
		i++;
	}
}
