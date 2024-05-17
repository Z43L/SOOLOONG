/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:00:50 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/14 08:14:41 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif


char	*extract_line(char *str);
char	*update(char *str);
char	*ft_get_next_line(int fd);
int		ft_strleng(const char *s);
char	*ft_strncpyg(char *dest, const char *src, size_t n);
char	*ft_strdupg(const char *string);
char	*ft_strjoing(char *s1, char *s2);
char	*ft_strchrg(char *s, int c);

#endif