/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_oficial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:01:03 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/19 23:25:28 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*bulogic(int fd, char *storage, char *temp, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!ft_strchrg(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoing(storage, buffer);
		free(storage);
		if (!temp)
			return (NULL);
		storage = temp;
	}
	return (storage);
}

char	*extract_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line = ft_strncpyg(line, str, i);
	line[i] = '\0';
	return (line);
}

char	*update(char *str)
{
	char	*nextline;
	char	*updated_str;
	
	nextline = ft_strchrg(str, '\n');
	if (!nextline)
	{
		return (NULL);
	}
	
	updated_str = ft_strdupg(nextline + 1);
	if (!updated_str)
		return (NULL);
	return (updated_str);
}

char	*ft_get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = ft_strdupg("");
	storage = bulogic(fd, storage, temp, buffer);
	if (storage[0] == '\0')
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	line = extract_line(storage);
	temp = update(storage);

	storage = temp;
	return (line);
}