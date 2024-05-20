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
	size_t	bytes_read;

	bytes_read = 0;
	while (!ft_strchrg(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			free(storage);
			return (NULL);
		}
		if (bytes_read == 0)
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
/**
 * * this fuction is the resposible of split lines 
 * about '\n' and storage lines
 * * in these funtion i will use ft_strcpy to copy 
 * the split lines in line
 * * and i will use ft_strdup is not have that copy
 * TODO: make that split not only for '\n' but split
 *  for '\n' and '\0'

 * @param line these is the value of the return and the
  variable where storage split lines
 * @param i is the counter who i use two travel the array 
*/

char	*extract_line(char *str)
{
	char	*line;
	int		i;

	i=0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	line = ft_strncpyg(line, str, i);
	line[i++] = '\0';
	return (line);
}
/**
 *
	* this fuction is the responsible to update de static
     variable who storage the size of buffer 
 * TODO: make that this funtion return de end line
 * @param storage is the static variable who use to defined the
 *  next line 

	* @param nexline is the variable that use to start
     the next line calling the function extract_line
 * @param line  is the return value this use ft_strdup 
*/

char	*update(char *str)
{
	char	*nextline;
	char	*updated_str;
	
	nextline = ft_strchrg(str, '\n');
	if (!nextline || !ft_strchrg(str + 1, '\0'))
	{
		return (NULL);
	}
	updated_str = ft_strdupg(nextline + 1);
	if (!updated_str)
		return (NULL);
	return (updated_str);
}

/**
 * * this funtion consist in read line a line
 * TODO: make that this funtion run

	* @param buffer int it we storage the lines to 
    before call a funtion update this will be str
 * @param line these is the return , we should 
 transform buffer in line 

	* @param storage these is the static variable 
    where we storage all of readed lines to continue next

	* @param reading these is the variable to 
    stemp storage of we read in the moment 
*/
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
	free(storage);
	storage = temp;
	return (line);
}
 
/* int	main(void)
{
	int fd = open("prueba", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	char *line;
	while ((line = gnl(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	line = gnl(fd);
	printf("%s", line);
	close(fd);
	return (0);
} */