/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:28:30 by gmorais-          #+#    #+#             */
/*   Updated: 2023/06/12 12:28:33 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	a;
	size_t	len;
	char	*dst;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (0);
	a = 0;
	while (s1[a])
		dst[i++] = s1[a++];
	a = 0;
	while (s2[a])
		dst[i++] = s2[a++];
	dst[i] = '\0';
	return (dst);
}

/*junta "s1" e "s2" dentro dum espaco de memoria alucado.
returna a memoria alucada.*/