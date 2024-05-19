/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:01:10 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/19 23:24:23 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strleng(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
	{
		s++;
	}
	return (s - start);
}

char	*ft_strncpyg(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strdupg(const char *string)
{
	char	*duplicada;
	size_t	i;
	size_t	len;

	len = ft_strleng(string);
	duplicada = malloc(len);
	if (duplicada == NULL)
		return (NULL);
	i = 0;
	while (string[i] != '\0')
	{
		duplicada[i] = string[i];
		i++;
	}
	duplicada[i] = '\0';
	return (duplicada);
}

char	*ft_strjoing(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		z;
	char	*ptr;

	len1 = ft_strleng(s1);
	len2 = ft_strleng(s2);
	ptr = malloc(len1 + len2 + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	z = 0;
	while (s1[i])
		ptr[z++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		ptr[z] = s2[i];
		z++;
		i++;
	}
	ptr[z] = '\0';
	return (ptr);
}

char	*ft_strchrg(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
