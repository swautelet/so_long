/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:41:52 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 16:20:35 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list_c	*ft_lstlast_c(t_list_c *lst)
{
	if (lst == NULL)
		return (NULL);
	while ((*lst).next != NULL)
	{
		lst = (*lst).next;
	}
	return (lst);
}

t_list_v	*ft_lstlast_v(t_list_v *lst)
{
	if (lst == NULL)
		return (NULL);
	while ((*lst).next != NULL)
	{
		lst = (*lst).next;
	}
	return (lst);
}
