/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:35:14 by marvin            #+#    #+#             */
/*   Updated: 2025/01/09 14:05:09 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*store_rest(char *text)
{
	char	*tmp;

	tmp = ft_strchr(text, '\n');
	if (tmp == NULL)
	{
		free (text);
		return (ft_strdup(""));
	}
	tmp = ft_strdup(tmp + 1);
	free (text);
	return (tmp);
}

char	*extract_line(char *text)
{
	int		i;
	char	*ext_line;
	char	*tmp;

	i = 0;
	ext_line = ft_calloc(1, ft_strlen(text) + 1);
	while (text[i] != '\0' && text[i] != '\n')
	{
		ext_line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		ext_line[i] = '\n';
	tmp = ft_strdup(ext_line);
	free (ext_line);
	return (tmp);
}

char	*text_update(char *text, char *readen)
{
	char	*tmp;

	if (!readen)
		return (NULL);
	if (!text)
		text = ft_calloc(1, 1);
	tmp = ft_strjoin(text, readen);
	free(text);
	return (tmp);
}

char	*read_file(char *text, char *readen, int fd)
{
	int	i;

	while (read(fd, readen, BUFFER_SIZE) > 0)
	{
		text = text_update(text, readen);
		i = 0;
		while (readen[i] != '\0')
			readen[i++] = '\0';
		if (ft_strchr(text, '\n'))
			break ;
	}
	return (text);
}

char	*get_next_line(int fd)
{
	char		*readen;
	static char	*text;
	char		*get_line;

	if (fd == -1)
		return (NULL);
	readen = ft_calloc(1, BUFFER_SIZE + 1);
	text = read_file(text, readen, fd);
	if (!text || text[0] == '\0')
	{
		free (readen);
		if (!text)
			return (NULL);
		free (text);
		return (NULL);
	}
	get_line = extract_line(text);
	text = store_rest(text);
	free (readen);
	return (get_line);
}

int	main(void)
{
	int	fd;
	char	*line;

	// Abrir un archivo de prueba
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo");
		return (1);
	}

	// Leer e imprimir líneas hasta el final del archivo
	while (1)
	{
	line = get_next_line(fd);
	if (line == NULL)
		break ;
	printf("%s", line);
	free(line); // Liberar memoria
	}

	// Cerrar el archivo
	close(fd);
	return (0);
}
