/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:11:05 by dmazo-ga          #+#    #+#             */
/*   Updated: 2024/12/19 19:18:34 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char	*s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		dup[i] = s[i];
	dup[len] = '\0';
	return (dup);
}
char *ft_strchr(const char *s, int c)
{
	int	i;
	char conv;
	
	i = 0;
	conv = (char)c;
	while (s[i] != '\0')
		if(s[i++] == conv)
			return ((char *)&s[i -1]);
	if (s[i] == conv)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int j;
	size_t len;
	char	*new_string;
	
	len = ft_strlen(s1) + ft_strlen(s2);
	new_string = malloc(len + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	return (new_string);
}
void	*ft_calloc(size_t n_elem, size_t size)
{
	size_t	total_size;
	size_t	i;
	void	*ptr;
	char	*tmp;
	
	if (n_elem == SIZE_MAX || size == SIZE_MAX
		|| (n_elem >= 4294967296 && size >= 4294967296))
		return (NULL);
	total_size = n_elem * size;
	ptr = malloc((size_t)total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	tmp = (char *)ptr;
	while (i < total_size)
		tmp[i++] = '\0';
	return (ptr);
}