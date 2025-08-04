/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yantoine <yantoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:49:09 by yantoine          #+#    #+#             */
/*   Updated: 2024/11/13 23:04:59 by yantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partie_entiere(double *entier, char *string, int i, double *sign)
{
	if (string[i] == '-')
	{
		*sign = -1;
		i++;
	}
	while (string[i] && ft_isdigit(string[i]))
	{
		*entier = *entier * 10 + (string[i] - '0');
		i++;
	}
	return (i);
}

//fonction qui convertie une string en double
double	ft_strtod(char *string)
{
	double		entier;
	double		decimal;
	double		diviseur;
	double		sign;
	int			i;

	i = 0;
	entier = 0;
	decimal = 0;
	diviseur = 1;
	sign = 1;
	i = partie_entiere(&entier, string, i, &sign);
	if (string[i] == '.')
	{
		i++;
		while (string[i] && ft_isdigit(string[i]))
		{
			decimal = decimal * 10 + (string[i] - '0');
			diviseur *= 10;
			i++;
		}
	}
	return ((entier + decimal / diviseur) * sign);
}
