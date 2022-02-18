/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:01:09 by simonwautel       #+#    #+#             */
/*   Updated: 2022/02/18 18:04:37 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlengnl(char *str)
{
	size_t	l;

	l = -1;
	while (str[++l])
	{
		if (str[l] == '\n')
		{
			l++;
			break ;
		}
	}
	l += 2;
	return (l);
}

void	ft_straddback2(char *newresult, char *buffer, ssize_t i, ssize_t size)
{
	ssize_t	l;

	l = -1;
	while (buffer[++l] && size - l > 0)
	{
		newresult[i + l] = buffer[l];
		if (buffer[l] == '\n')
		{
			buffer[l++] = -1;
			break ;
		}
		buffer[l] = -1;
	}
	newresult[i + l] = '\0';
	if (size == l)
		while (buffer[l])
			buffer[l++] = -1;
}

char	*ft_straddback(char *result, char *buffer, ssize_t size)
{
	char	*newresult;
	ssize_t	i;

	i = -1;
	newresult = malloc(sizeof(char) * (size + ft_strlen(result)));
	if (!newresult)
	{
		free (result);
		return (NULL);
	}
	while (result[++i])
		newresult[i] = result[i];
	free (result);
	ft_straddback2(newresult, buffer, i, size);
	return (newresult);
}

int	ft_end_of_line(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_initialize(char *buffer)
{
	char		*new;
	ssize_t		i;
	ssize_t		l;

	i = 0;
	while (buffer[i] && buffer[i] == -1)
		i++;
	new = malloc((ft_strlen(&buffer[i])) * sizeof(char));
	if (!new)
		return (NULL);
	if (!buffer[i])
	{
		new[0] = '\0';
		return (new);
	}
	l = 0;
	while (buffer[i + l] && buffer[i + l] != -1)
	{
		new[l] = buffer[i + l];
		buffer[i + l] = -1;
		if (new[l++] == '\n')
			break ;
	}
	new[l] = '\0';
	return (new);
}
