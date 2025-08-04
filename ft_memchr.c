/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yantoine <yantoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:03:40 by yantoine          #+#    #+#             */
/*   Updated: 2024/10/25 21:46:01 by yantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			index;

	p = (unsigned char *)s;
	index = 0;
	while (p[index] && index < n)
	{
		if (p[index] == (unsigned char) c)
			return ((void *)(p + index));
		index++;
	}
	return (NULL);
}
