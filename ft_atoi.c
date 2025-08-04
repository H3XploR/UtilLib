/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexplor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:24 by hexplor           #+#    #+#             */
/*   Updated: 2024/07/01 17:59:13 by yantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' \
	|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_fsign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *text)
{
	long	sign;
	long	number;

	number = 0;
	sign = 1;
	while (ft_isspace(*text) == 1)
		text++;
	if (*text == '-' || *text == '+')
	{
		sign = ft_fsign(*text);
		text++;
	}
	while (ft_isdigit(*text) == 1)
	{
		number *= 10;
		number += *text - '0';
		text++;
	}
	return (sign * number);
}
