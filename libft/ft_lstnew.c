/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:18:12 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 16:22:31 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_c	*ft_lstnew_c(void *content)
{
	t_list_c	*new;

	new = malloc (sizeof (t_list_c));
	if (new == NULL)
		return (NULL);
	(*new).content = content;
	(*new).next = NULL;
	return (new);
}

t_list_v	*ft_lstnew_v(void *content)
{
	t_list_v	*new;

	new = malloc (sizeof (t_list_v));
	if (new == NULL)
		return (NULL);
	(*new).content = content;
	(*new).next = NULL;
	return (new);
}
