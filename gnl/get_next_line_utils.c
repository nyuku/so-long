/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:41:58 by angela            #+#    #+#             */
/*   Updated: 2023/03/04 16:44:23 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// //fonction qui vérifie dans la stash si \n
// int check_newline(char *str);

// //copie ce que renvoie read vers le buffer vers la stash, static
// void    cpy_stash(char *str);

#include "so_long.h”

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		slen;
	int		i;
	char	*str;

	slen = ft_strlen((char *)s1);
	i = -1;
	str = (char *)malloc(slen + 1);
	if (!str)
		return (NULL);
	while (++i < slen)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len + 1)
	{
		if (str[i] == (char)c)
			return (&((char *)str)[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	size;

	res = malloc(sizeof(char) * (len + 1));
	if (!*s)
		return (NULL);
	if (!res)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	while (i < len && start < size)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
