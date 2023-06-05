/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:35:37 by gmorais-          #+#    #+#             */
/*   Updated: 2023/06/05 13:57:47 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen_sec(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int	stashfree(char *buff)
{
	int	i;
	int	j;
	int	true;

	i = 0;
	j = 0;
	true = 0;
	while (buff[i])
	{
		if (true)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			true = 1;
		buff[i++] = '\0';
	}
	return (true);
}

char	*ft_strjoin_sec(char *str1, char *str2)
{
	int		j;
	int		i;
	char	*mem;

	j = 0;
	i = 0;
	mem = malloc(ft_strlen_sec(str1) + ft_strlen_sec(str2) + 1);
	if (!mem)
		return (NULL);
	while (str1 && str1[i])
	{
		mem[i] = str1[i];
		i++;
	}
	free(str1);
	while (str2[j])
	{
		mem[i++] = str2[j];
		if (str2[j++] == '\n')
			break ;
	}
	mem[i] = '\0';
	return (mem);
}
