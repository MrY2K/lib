/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_impoved.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:30:58 by achoukri          #+#    #+#             */
/*   Updated: 2025/09/26 17:31:33 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_atoi_improved - a9wad atoi in existence – 
 * convert ASCII string to int with optional error checking
 *
 * This function parses a C‐string for an integer, handling:
 *   • leading whitespace
 *   • optional '+' or '-' sign
 *   • overflow detection (> INT_MAX)
 *   • optional strict checks for “no digits” or “trailing garbage”
 *
 * Behavior modes:
 *   • Lax mode (flag == NULL):
 *       – Parses leading digits into an int
 *       – On overflow returns -69
 *       – On no digits returns 0
 *       – Ignores any characters after the digits
 *   • Strict mode (flag != NULL):
 *       – On any error (overflow, no digits, or non‐digit after digits)
 *         sets *flag = -1 and returns -69
 *       – On success leaves *flag unchanged (0) and returns the parsed value
 *       – To use strict mode in your code :
 *           int flag = 0;
 *           int val  = ft_atoi_improved(str, &flag);
 *           if (flag != 0)
 *               handle error: val == -69
 *
 * @param str   NUL‐terminated string to convert
 * @param flag  if non‐NULL, pointer to int that will be set to -1 on error
 *              or left untouched on success; if NULL, errors are not flagged
 * @return      parsed integer value, or -69 on error (always), or 0 on no‐digit
 *              in lax mode
 */

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static void	ft_flag_err(int *flag)
{
	if (flag)
		*flag = -1;
}

static int	skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

static int	handle_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_improved(const char *str, int *flag)
{
	int			sign;
	long long	result;
	int			digits;
	int			i;

	sign = 1;
	result = 0;
	digits = 0;
	i = skip_spaces(str);
	sign = handle_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digits++;
		if ((result > INT_MAX / 10)
			|| (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
			return (ft_flag_err(flag), -69);
		result = result * 10 + str[i++] - '0';
	}
	if (digits == 0)
		if (flag)
			return (ft_flag_err(flag), -69);
	if (flag && str[i] != '\0')
		return (ft_flag_err(flag), -69);
	return ((int)(result * sign));
}
