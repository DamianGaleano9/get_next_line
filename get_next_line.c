/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:35:14 by marvin            #+#    #+#             */
/*   Updated: 2024/12/19 21:35:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line"

char *store_rest (char *text)
{
	char *tmp;

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